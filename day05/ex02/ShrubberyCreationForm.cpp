/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:08:05 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 11:58:27 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * Constructors & Destructor
 */

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & origin ) : Form(origin.getName(), 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

/**
 * Operators
 */

ShrubberyCreationForm   &ShrubberyCreationForm::operator = ( ShrubberyCreationForm const & value )
{
    Form::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

void    ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if (this->getSigned() && executor.getGrade() <= this->getExecGrade())
    {
        std::ofstream   os(this->getName() + "_shrubbery");

        os <<
        "          &&& &&  & &&        " << std::endl <<
        "      && &\\/&\\|& ()|/ @, &&   " << std::endl <<
        "      &\\/(/&/&||/& /_/)_&/_&  " << std::endl <<
        "   &() &\\/&|()|/&\\/ '%\" & () " << std::endl <<
        "  &_\\_&&_\\ |& |&&/&__%_/_& && " << std::endl <<
        "&&   && & &| &| /& & % ()& /&&" << std::endl <<
        " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl <<
        "     &&     \\|||              " << std::endl <<
        "             |||              " << std::endl <<
        "             |||              " << std::endl <<
        "             |||              " << std::endl <<
        "       , -=-~  .-^- _         " << std::endl;

        os.close();
        std::cout << "Shrubbery Form has been executed by " << executor.getName() << std::endl;
    }
    else if (!this->getSigned())
		std::cout << "A Bureaucrat must signed this form first before it can be requested." << std::endl;
	else
		throw Form::GradeTooLowException();
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, ShrubberyCreationForm const & value )
{
	os << "Shrubbery Creation Form Details:" << std::endl
        << "Target: " << value.getName() << std::endl
        << "Signing Grade Requirement: " << value.getSignGrade() << std::endl
        << "Execution Grade Requirement: " << value.getExecGrade() << std::endl;
	
    if (value.getSigned())
        os << "Form has been signed." << std::endl;
	else
        os << "Form has not been signed yet." << std::endl;
	
    return os;
}
