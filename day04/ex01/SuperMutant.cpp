/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:09:30 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 15:30:34 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

/**
 * Constructors & Destructor
 */

SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & origin ) : Enemy(origin)
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant( void )
{
    std::cout << "Aaargh ..." << std::endl;
}

/**
 * Operators
 */

SuperMutant &SuperMutant::operator = ( SuperMutant const & value )
{
    Enemy::operator=(value);
    return *this;
}

/**
 * Public Methods
 */

void    SuperMutant::takeDamage( int amount )
{
    Enemy::takeDamage(amount - 3);
}
