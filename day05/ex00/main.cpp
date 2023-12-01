/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:24:10 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 15:18:22 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat a("Cedric Page", 1);
    Bureaucrat b("Julien Chièze", 149);

    try
    {
        b.decrementGrade();
        b.decrementGrade();
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.incrementGrade();
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }    
    
    std::cout << a;
    std::cout << b;

    return 0;
}
