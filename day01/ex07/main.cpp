/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:03:15 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 13:27:31 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <libgen.h>

void    findAndReplace( std::string * content, const std::string from, const std::string to )
{
    size_t  pos = 0;

    while ((pos = content->find(from, pos)) != std::string::npos)
    {
        content->replace(pos, from.length(), to);
        pos += to.length();
    }
}

int     main( int argc, char const *argv[] )
{
    if (argc < 4)
    {
        std::cout << argv[0] << " <file> <from> <to>" << std::endl;
        return 1;
    }

    std::string file(argv[1]), from(argv[2]), to(argv[3]);

    if (file.empty() || from.empty() || to.empty())
    {
        std::cout << "error: At least one args is empty" << std::endl;
        return 1;
    }

    std::ifstream   is;
    is.open(file, std::ios::binary);

    if (is.fail())
    {
        std::cout << "error: " << strerror(errno) << std::endl;
        return 1;
    }
    
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);

    char * buff = new char[length];
    is.read(buff, length);

    is.close();

    std::string content(buff);
    delete [] buff;

    findAndReplace(&content, from, to);

    std::string filename(basename((char *)file.c_str()));
    filename = filename.append(".replace");

    std::cout << filename << std::endl;

    std::ofstream   os;
    os.open(filename);

    if (os.fail())
    {
        std::cout << "error: " << strerror(errno) << std::endl;
        return 1;
    }
    
    os << content;

    is.close();

    return 0;
}
