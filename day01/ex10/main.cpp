/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:35:34 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 14:53:03 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

static void readFile( std::ifstream & is )
{
    is.seekg(0, is.end);
    size_t  length = is.tellg();
    is.seekg(0, is.beg);

    char * buff = new char[length];
    is.read(buff, length);

    std::cout.write(buff, length);

    delete [] buff;
}

int main( int argc, char const *argv[] )
{
    if (argc < 2)
    {
        for (std::string line; std::getline(std::cin, line);)
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::ifstream   is;
            is.open(argv[i]);

            if (is.fail())
            {
                std::cout << "error: " << strerror(errno) << std::endl;
                continue;
            }

            readFile(is);

            is.close();
        }
    }

    return 0;
}
