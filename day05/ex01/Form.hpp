/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:24:22 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 15:14:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <fstream>

#include "Bureaucrat.hpp"

class	Form
{
private:
    std::string const   name;
    bool                isSigned;
    unsigned int const  signGrade;
    unsigned int const  execGrade;

public:
    Form( void );
    Form( std::string const _name, unsigned int _signGrade, unsigned int _execGrade );
    Form( Form & origin );
    ~Form( void );
    
    Form    &operator = ( Form const & value );

    std::string const   &getName( void ) const;
    bool const          &getSigned( void ) const;
    unsigned int const  &getSignGrade( void ) const;
    unsigned int const  &getExecGrade( void ) const;

    void    beSigned( Bureaucrat & b );

    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException( void );
            GradeTooHighException( GradeTooHighException const & origin );
            ~GradeTooHighException( void ) throw();
            
            GradeTooHighException   &operator = ( GradeTooHighException const & value );
            
            const char  *what( void ) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException( void );
            GradeTooLowException( GradeTooLowException const & origin );
            ~GradeTooLowException( void ) throw();
            
            GradeTooLowException    &operator = ( GradeTooLowException const & value );
            
            const char  *what( void ) const throw();
    };
}; 

std::ostream    &operator << ( std::ostream & os, Form const & value ); 

#endif
