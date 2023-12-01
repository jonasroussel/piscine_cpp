/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:34:21 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:01:30 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/**
 * Constructors & Destructor
 */

Victim::Victim( std::string _name ) : name(_name)
{
    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim( Victim const & _value ) : name(_value.name)
{
    std::cout << "Some random victim called " << _value.name << " just popped !" << std::endl;
}

Victim::~Victim( void )
{
    std::cout << "Victim " << getName() << " just died for no apparent reason !" << std::endl;
}

/**
 * Operators
 */

Victim  &Victim::operator = ( Victim const & _value )
{
    this->name = _value.name;
    return *this;
}

/**
 * Public Methods
 */

void    Victim::getPolymorphed( void ) const
{
    std::cout << getName() << " has been turned into a cute little sheep !" << std::endl;
}

/**
 * Getters & Settings
 */

std::string Victim::getName( void ) const
{
    return this->name;
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Victim const & _value )
{
    os << "I'm " << _value.getName() << " and I like otters !" << std::endl;
    return os;
}
