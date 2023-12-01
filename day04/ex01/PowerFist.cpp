/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:47:58 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:13:48 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/**
 * Constructors & Destructor
 */

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist( PowerFist const & origin ) : AWeapon(origin) {}

PowerFist::~PowerFist( void ) {}

/**
 * Operators
 */

PowerFist &PowerFist::operator = ( PowerFist const & value )
{
    AWeapon::operator=(value);
    return *this;
}

/**
 * public Methods
 */

void    PowerFist::attack( void ) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
