/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:22:59 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:01:37 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/**
 * Constructors & Destructor
 */

Sorcerer::Sorcerer( std::string _name, std::string _title ) : name(_name), title(_title)
{
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & _value ) : name(_value.name), title(_value.title)
{
    std::cout << _value.name << ", " << _value.title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer( void )
{
    std::cout << getName() << ", " << getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

/**
 * Operators
 */

Sorcerer        &Sorcerer::operator = ( Sorcerer const & _value )
{
    this->name = _value.name;
    this->title = _value.title;
    return *this;
}

/**
 * Public Methods
 */

void    Sorcerer::polymorph( Victim const & victim ) const
{
    victim.getPolymorphed();
}

/**
 * Getters & Settings
 */

std::string Sorcerer::getName( void ) const
{
    return this->name;
}

std::string Sorcerer::getTitle( void ) const
{
    return this->title;
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Sorcerer const & _value )
{
    os << "I am " << _value.getName() << ", " << _value.getTitle() << ", and I like ponies !" << std::endl;
    return os;
}
