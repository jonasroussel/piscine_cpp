/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:57:33 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 12:12:11 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    Bureaucrat a("Cedric Page", 1);
    Bureaucrat b("Julien Chièze", 150);

    ShrubberyCreationForm fa("home");
    RobotomyRequestForm fb("Mark Zuckerberg");
    PresidentialPardonForm fc("Patrick Balkany");

    try
    {
        b.signForm(&fa);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.signForm(&fa);
        a.signForm(&fb);
        a.signForm(&fc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b.executeForm(&fa);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.executeForm(&fa);
        a.executeForm(&fb);
        a.executeForm(&fc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << fa;
    std::cout << fb;
    std::cout << fc;

    return 0;
}
