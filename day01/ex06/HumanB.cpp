/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:54:40 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:26:24 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string _name ) : name(_name), weapon(nullptr) {}

HumanB::~HumanB( void ) {}

void    HumanB::attack( void )
{
    if (this->weapon != nullptr)
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with his hands" << std::endl;
}

void    HumanB::setWeapon( Weapon& weapon )
{
    this->weapon = &weapon;
}
