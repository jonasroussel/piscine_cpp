/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:27:15 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 12:32:14 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>

# include "Victim.hpp"

class Peon : public Victim
{
private:

public:
    Peon( void );
    Peon( std::string _name );
    Peon( Peon const & _value );
    ~Peon( void );

    Peon    &operator = ( Peon const & _value );

    void    getPolymorphed( void ) const;
};

std::ostream    &operator << ( std::ostream & os, Peon const & _value ); 

#endif
