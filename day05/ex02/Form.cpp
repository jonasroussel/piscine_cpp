/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:24:14 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 15:16:25 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**
 * Constructor & Destructor
 */

Form::Form(
    std::string const _name,
    unsigned int _signGrade,
    unsigned int _execGrade
):
    name(_name),
    isSigned(false),
    signGrade(_signGrade),
    execGrade(_execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form & origin ) :
    name(origin.name),
    isSigned(origin.isSigned),
    signGrade(origin.signGrade),
    execGrade(origin.execGrade)
{}

Form::~Form( void ) {}

/**
 * Operators
 */

Form    &Form::operator = ( Form const & value ) 
{
	this->isSigned = value.isSigned;
	return *this;
}

/**
 * Getters
 */

std::string const   &Form::getName( void ) const
{
	return this->name;
}

bool const          &Form::getSigned( void ) const
{
	return this->isSigned;
}

unsigned int const  &Form::getSignGrade( void ) const
{
	return this->signGrade;
}

unsigned int const  &Form::getExecGrade( void ) const
{
	return	this->execGrade;
}

/**
 * Setters
 */

void    Form::beSigned( Bureaucrat & b )
{
	if (b.getGrade() > this->signGrade)
	{
		std::cout << "<Bureaucrat " << b.getName() << "> cannot sign <" << this->name << "> because: ";
		throw Form::GradeTooLowException();
	}
	else
	{
		if (this->isSigned)
			std::cout << "<Bureaucrat " << b.getName() << "> cannot sign <" << this->name << "> because: form is already signed" << std::endl;
		else
		{
			std::cout << "<Bureaucrat " << b.getName() << "> signs <" << this->name << ">" << std::endl;
			this->isSigned = true;
		}
	}
}

/*
** GradeTooHighException Nested Class
*/

Form::GradeTooHighException::GradeTooHighException( void ) {}

Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const & origin )
{
    (void)origin;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Form::GradeTooHighException &Form::GradeTooHighException::operator = ( GradeTooHighException const & value ) 
{
	(void)value;
	return *this;
}

const char  *Form::GradeTooHighException::what( void ) const throw()
{
	return "grade too high";
}

/*
** GradeTooLowException Nested Class
*/

Form::GradeTooLowException::GradeTooLowException( void ) {}

Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const & origin )
{
    (void)origin;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Form::GradeTooLowException  &Form::GradeTooLowException::operator = ( GradeTooLowException const & value ) 
{
	(void)value;
	return *this;
}

const char  *Form::GradeTooLowException::what( void ) const throw()
{
	return "grade too low";
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Form const & value )
{
	os << "Form Details:" << std::endl
        << "Name: " << value.getName() << std::endl
        << "Signing Grade Requirement: " << value.getSignGrade() << std::endl
        << "Execution Grade Requirement: " << value.getExecGrade() << std::endl;
        
	if(value.getSigned())
        os << "Form has been signed." << std::endl;
	else
        os << "Form has not been signed yet." << std::endl;
        
	return os;
}
