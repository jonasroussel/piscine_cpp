/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:54:24 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:18:16 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon& _weapon ) : name(_name), weapon(_weapon) {}

HumanA::~HumanA( void ) {}

void    HumanA::attack( void )
{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
