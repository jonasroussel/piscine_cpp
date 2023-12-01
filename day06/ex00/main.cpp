/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:32:22 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 13:02:34 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <string>

int main( int argc, char const *argv[] )
{
    if (argc < 2)
    {
        std::cout << argv[0] << " <exp>" << std::endl;
        return 1;
    }

    std::cout << "char: ";
    try
    {
        char val = static_cast<char>(std::stoi(argv[1]));
        
        if (!isprint(val))
            std::cout << "Non displayable" << std::endl;
        else if (val == '*')
            std::cout << "'" << val << "'" << std::endl;
        else
            std::cout << val << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try
    {
        int val = static_cast<int>(std::stoi(argv[1]));

        std::cout << val << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "impossible" << std::endl;
    }
    
    std::cout << "float: ";
    try
    {
        float val = static_cast<float>(std::stof(argv[1]));

        if (isnan(val) || isinf(val))
            std::cout << val << "f" << std::endl;
        else if (val == static_cast<int>(val))
            std::cout << val << ".0f" << std::endl;
        else
            std::cout << val << "f" << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "double: ";
    try
    {
        double val = static_cast<double>(std::stod(argv[1]));

        if (val == static_cast<int>(val))
            std::cout << val << ".0" << std::endl;
        else
            std::cout << val << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "impossible" << std::endl;
    }

    return 0;
}
