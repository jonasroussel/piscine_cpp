/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:24:38 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 13:43:30 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
protected:
    std::string name;
    
public:
    Victim( void );
    Victim( std::string _name );
    Victim( Victim const & _value );
    ~Victim( void );

    Victim  &operator = ( Victim const & _value );

    virtual void    getPolymorphed( void ) const;

    std::string getName( void ) const;
};

std::ostream    &operator << ( std::ostream & os, Victim const & _value ); 

#endif
