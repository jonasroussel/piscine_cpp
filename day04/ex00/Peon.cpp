/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:43:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:46:27 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/**
 * Constructors & Destructor
 */

Peon::Peon( std::string _name ) : Victim(_name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon( Peon const & _value ) : Victim(_value)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon( void )
{
    std::cout << "Bleuark..." << std::endl;
}

/**
 * Operators
 */

Peon  &Peon::operator = ( Peon const & _value )
{
    Victim::operator=(_value);
    return *this;
}

/**
 * Public Methods
 */

void    Peon::getPolymorphed( void ) const
{
    std::cout << getName() << " has been turned into a pink pony !" << std::endl;
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Peon const & _value )
{
    os << "I'm " << _value.getName() << " and I like otters !" << std::endl;
    return os;
}
