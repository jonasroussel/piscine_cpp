/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:57:33 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 12:22:34 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern  someRandomIntern;
    
    Form*   f;
    f = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *f;
    delete f;
    f = someRandomIntern.makeForm("presidential pardon", "Patrick Balkany");
    std::cout << *f;
    delete f;
    f = someRandomIntern.makeForm("shrubbery creation", "home");
    std::cout << *f;
    delete f;

    return 0;
}
