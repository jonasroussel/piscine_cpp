/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:08 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 12:07:22 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * Constructors & Destructor
 */

Bureaucrat::Bureaucrat( std::string _name, unsigned int _grade ) : name(_name)
{
    if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = _grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & origin ) :
    name(origin.name),
    grade(origin.grade)
{}

Bureaucrat::~Bureaucrat( void ) {}

/**
 * Operators
 */

Bureaucrat  &Bureaucrat::operator = ( Bureaucrat const & value )
{
    this->grade = value.grade;
    return *this;
}

/**
 * Public Methods
 */

void    Bureaucrat::signForm( Form * form )
{
    form->beSigned(*this);
}

void    Bureaucrat::executeForm( Form * form )
{
    try
    {
        form->execute(*this);
        std::cout << getName() << " executes " << form->getName() << std::endl;
    }
    catch (Form::GradeTooLowException & ex)
    {
        std::cout << getName() << " failed to execute form because: " << ex.what() << std::endl;
    }
}

/**
 * Getters
 */

std::string const   &Bureaucrat::getName( void ) const
{
    return this->name;
}

unsigned int const  &Bureaucrat::getGrade( void ) const
{
    return this->grade;
}

/**
 * Setters
 */

void    Bureaucrat::incrementGrade( void )
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void    Bureaucrat::decrementGrade( void )
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

/**
 * GradeTooHighException Nested Class
 */

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {}

Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const & origin )
{
    (void)origin;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Bureaucrat::GradeTooHighException   &Bureaucrat::GradeTooHighException::operator = ( GradeTooHighException const & value ) 
{
    (void)value;
	return *this;
}

const char  *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("error: grade too high");
}

/**
 * GradeTooLowException Nested Class
 */

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {}

Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & origin )
{
    (void)origin;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Bureaucrat::GradeTooLowException    &Bureaucrat::GradeTooLowException::operator = ( GradeTooLowException const & value ) 
{
    (void)value;
	return *this;
}

const char  *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("error: grade too low");
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Bureaucrat const & value )
{
    std::cout << value.getName() << ", bureaucrat grade " << value.getGrade() << std::endl;
    return os;
}
