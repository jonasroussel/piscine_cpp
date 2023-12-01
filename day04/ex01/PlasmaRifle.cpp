/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:40:03 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:15:20 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/**
 * Constructors & Destructor
 */

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & origin ) : AWeapon(origin) {}

PlasmaRifle::~PlasmaRifle( void ) {}

/**
 * Operators
 */

PlasmaRifle &PlasmaRifle::operator = ( PlasmaRifle const & value )
{
    AWeapon::operator=(value);
    return *this;
}

/**
 * public Methods
 */

void    PlasmaRifle::attack( void ) const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
