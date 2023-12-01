/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:01:19 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 11:48:49 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm( void );
    PresidentialPardonForm( std::string target );
    PresidentialPardonForm( PresidentialPardonForm const & origin );
    ~PresidentialPardonForm( void );

    PresidentialPardonForm   &operator = ( PresidentialPardonForm const & value );

    void    execute( Bureaucrat const & executor ) const;
};

std::ostream    &operator << ( std::ostream & os, PresidentialPardonForm const & value ); 

#endif
