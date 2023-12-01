/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:01:19 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 17:06:24 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBETUCREATIONFORM_HPP
# define SHRUBBETUCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm( void );
    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm( ShrubberyCreationForm const & origin );
    ~ShrubberyCreationForm( void );

    ShrubberyCreationForm   &operator = ( ShrubberyCreationForm const & value );

    void    execute( Bureaucrat const & executor ) const;
};

std::ostream    &operator << ( std::ostream & os, ShrubberyCreationForm const & value ); 

#endif
