/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:41:48 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/16 14:29:37 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <sstream>
#include <stack>

const std::string   OPS = "-+/*";

std::string infixToPostfix( std::string const & infix )
{
    std::stringstream   stream;
    std::stack<int>     stack;

    std::stringstream   input(infix);
    std::string         token;

    while (std::getline(input, token, ' '))
    {
        if (token.empty())
            continue;

        size_t idx = OPS.find(token[0]);

        if (idx != std::string::npos && token[1] == '\0')
        {
            while (!stack.empty())
            {
                int prec2 = stack.top() / 2;
                int prec1 = idx / 2;

                if (prec2 > prec1 || prec2 == prec1)
                {
                    stream << OPS[stack.top()] << ' ';
                    stack.pop();
                }
                else break;
            }

            stack.push(idx);
        }
        else if (token == "(")
            stack.push(-2);
        else if (token == ")")
        {
            while (stack.top() != -2)
            {
                stream << OPS[stack.top()] << ' ';
                stack.pop();
            }
            stack.pop();
        }
        else
            stream << token << ' ';
    }

    while (!stack.empty())
    {
        stream << OPS[stack.top()] << ' ';
        stack.pop();
    }

    return stream.str();
}

Fixed   evaluate( std::string const & postfix )
{
    std::stack<Fixed>   stack;

    std::stringstream   input(postfix);
    std::string         token;

    while (std::getline(input, token, ' '))
    {
        if (token.empty())
            continue;

        size_t idx = OPS.find(token[0]);

        if (idx != std::string::npos && token[1] == '\0')
        {
            char op = OPS[idx];

            Fixed op2 = stack.top();
            stack.pop();
            Fixed op1 = stack.top();
            stack.pop();

            Fixed result;

            if (op == '-')
                result = op1 - op2;
            else if (op == '+')
                result = op1 + op2;
            else if (op == '/')
                result = op1 / op2;
            else if (op == '*')
                result = op1 * op2;
            
            stack.push(result);
        }
        else
            stack.push(Fixed(std::stof(token)));
    }

    return stack.top();
}
 
int main( int argc, char const *argv[] )
{
    if (argc < 2)
    {
        std::cout << "error: No argument" << std::endl;
        return 1;
    }

    std::string infix(argv[1]);
    
    try
    {
        std::string postfix = infixToPostfix(infix);

        if (postfix.empty())
            throw std::invalid_argument("");
        
        Fixed result = evaluate(postfix);
        std::cout << evaluate(postfix) << std::endl;
    }
    catch (std::invalid_argument ex)
    {
        std::cout << "error: Invalid argument" << std::endl;
        return 2;
    }

    return 0;
}
