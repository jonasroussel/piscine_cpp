/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:24:33 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:34:21 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/**
 * Constructors & Destructor
 */

AWeapon::AWeapon(
    std::string const & _name,
    int _apcost,
    int _damage
):
    name(_name), 
    apcost(_apcost),
    damage(_damage)
{}

AWeapon::AWeapon( AWeapon const & origin ) :
    name(origin.name),
    apcost(origin.apcost),
    damage(origin.damage)
{}

AWeapon::~AWeapon( void ) {}

/**
 * Operators
 */

AWeapon &AWeapon::operator = ( AWeapon const & value )
{
    this->name = value.name;
    this->apcost = value.apcost;
    this->damage = value.damage;
    return *this;
}

/**
 * Getters & Setters
 */

std::string const   &AWeapon::getName( void ) const
{
    return this->name;
}

int                 AWeapon::getAPCost( void ) const
{
    return this->apcost;
}

int                 AWeapon::getDamage( void ) const
{
    return this->damage;
}
