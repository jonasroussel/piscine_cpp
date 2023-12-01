/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:08:05 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 11:58:16 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**
 * Constructors & Destructor
 */

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form(target, 25, 5)
{
    srand(time(NULL));
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & origin ) : Form(origin.getName(), 25, 5)
{
    srand(time(NULL));
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

/**
 * Operators
 */

PresidentialPardonForm   &PresidentialPardonForm::operator = ( PresidentialPardonForm const & value )
{
    Form::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

void    PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSigned() && executor.getGrade() <= this->getExecGrade())
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else if (!this->getSigned())
		std::cout << "A Bureaucrat must signed this form first before it can be requested." << std::endl;
	else
		throw Form::GradeTooLowException();
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, PresidentialPardonForm const & value )
{
	os << "Presidential Pardon Form Details:" << std::endl
        << "Target: " << value.getName() << std::endl
        << "Signing Grade Requirement: " << value.getSignGrade() << std::endl
        << "Execution Grade Requirement: " << value.getExecGrade() << std::endl;
	
    if (value.getSigned())
        os << "Form has been signed." << std::endl;
	else
        os << "Form has not been signed yet." << std::endl;
	
    return os;
}
