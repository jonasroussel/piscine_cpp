/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:16:03 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 12:19:01 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**
 * Constructors & Destructor
 */

Intern::Intern(void) {}

Intern::Intern( Intern & origin ) {}

Intern::~Intern(void) {}

/**
 * Operators
 */

Intern  &Intern::operator = ( Intern const & value ) 
{
	(void)value;
	return (*this);
}

/**
 * Public Methods
 */

Form    *Intern::makeForm( std::string form, std::string target )
{
	if (form == "shrubbery creation")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "robotomy request")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "presidential pardon")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		std::cout << "Itern failed to create " << form << std::endl;
	
    return nullptr;
}
