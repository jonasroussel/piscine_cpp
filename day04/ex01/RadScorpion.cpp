/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:32:05 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:24:38 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

/**
 * Constructors & Destructor
 */

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const & origin ) : Enemy(origin)
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion( void )
{
    std::cout << "* SPROTCH *" << std::endl;
}

/**
 * Operators
 */

RadScorpion &RadScorpion::operator = ( RadScorpion const & value )
{
    Enemy::operator=(value);
    return *this;
}
