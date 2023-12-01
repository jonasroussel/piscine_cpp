/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:08:05 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 11:58:23 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/**
 * Constructors & Destructor
 */

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form(target, 72, 45)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & origin ) : Form(origin.getName(), 72, 45)
{
    srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/**
 * Operators
 */

RobotomyRequestForm   &RobotomyRequestForm::operator = ( RobotomyRequestForm const & value )
{
    Form::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

void    RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSigned() && executor.getGrade() <= this->getExecGrade())
	{
		std::cout << "* Bzzt... BZZZT... VrrrrRrRRRRRrrrr... *" << std::endl;
		
        int rng = rand() % 2;

        if (rng == 0)
			std::cout << this->getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getName() << " has failed to be robotomized" << std::endl;
	}
	else if (!this->getSigned())
		std::cout << "A Bureaucrat must signed this form first before it can be requested." << std::endl;
	else
		throw Form::GradeTooLowException();
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, RobotomyRequestForm const & value )
{
	os << "Robotomy Request Form Details:" << std::endl
        << "Target: " << value.getName() << std::endl
        << "Signing Grade Requirement: " << value.getSignGrade() << std::endl
        << "Execution Grade Requirement: " << value.getExecGrade() << std::endl;
	
    if (value.getSigned())
        os << "Form has been signed." << std::endl;
	else
        os << "Form has not been signed yet." << std::endl;
	
    return os;
}
