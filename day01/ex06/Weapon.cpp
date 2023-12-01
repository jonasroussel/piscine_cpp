/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:52:42 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:11:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
    this->type = type;
}

Weapon::Weapon( void ) {}

Weapon::~Weapon( void ) {}

const std::string&  Weapon::getType( void )
{
    return this->type;
}

void                Weapon::setType( std::string type )
{
    this->type = type;
}
