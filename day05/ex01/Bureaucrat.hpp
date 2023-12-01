/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:25:03 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 15:15:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <fstream>

class Form;

class Bureaucrat
{
private:
    std::string const   name;
    unsigned int        grade;

public:
    Bureaucrat( void );
    Bureaucrat( std::string _name, unsigned int _grade );
    Bureaucrat( Bureaucrat const & origin );
    ~Bureaucrat( void );

    Bureaucrat  &operator = ( Bureaucrat const & value );

    void    signForm( Form * form );

    std::string const   &getName( void ) const;
    unsigned int const  &getGrade( void ) const;

    void                incrementGrade( void );
    void                decrementGrade( void );

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

std::ostream    &operator << ( std::ostream & os, Bureaucrat const & value ); 

#endif
