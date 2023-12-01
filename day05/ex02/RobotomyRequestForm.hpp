/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:01:19 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 11:51:59 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm( void );
    RobotomyRequestForm( std::string target );
    RobotomyRequestForm( RobotomyRequestForm const & origin );
    ~RobotomyRequestForm( void );

    RobotomyRequestForm   &operator = ( RobotomyRequestForm const & value );

    void    execute( Bureaucrat const & executor ) const;
};

std::ostream    &operator << ( std::ostream & os, RobotomyRequestForm const & value ); 

#endif
