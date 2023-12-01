/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:38:32 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:23:36 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/**
 * Constructors & Desctructor
 */

Character::Character( std::string const & _name ) :
    name(_name),
    ap(40),
    weapon(nullptr)
{}

Character::Character( Character const & origin ) :
    name(origin.name),
    ap(origin.ap),
    weapon(origin.weapon)
{}

Character::~Character( void ) {}

/**
 * Operators
 */

Character   &Character::operator = ( Character const & value )
{
    this->name = value.name;
    this->ap = value.ap;
    this->weapon = value.weapon;
    return *this;
}

/**
 * Public Methods
 */

void    Character::recoverAP( void )
{
    if (getAP() + 10 >= 40)
        this->ap = 40;
    else
        this->ap += 10;
}

void    Character::equip( AWeapon * weapon )
{
    this->weapon = weapon;
}

void    Character::attack( Enemy * enemy )
{
    AWeapon *weapon = getWeapon();

    if (weapon != nullptr)
    {
        if (weapon->getAPCost() <= getAP())
        {
            std::cout << getName() << " attacks " << enemy->getType() << " with a " << weapon->getName() << std::endl;
            
            this->ap -= weapon->getAPCost();
            
            weapon->attack();
            enemy->takeDamage(weapon->getDamage());
            
            if (enemy->getHP() <= 0)
                delete enemy;
        }
    }
    else
    {
        std::cout << getName() << " attacks " << enemy->getType() << " without any weapon" << std::endl;
    }
}

/**
 * Getters & Setters
 */

std::string const   &Character::getName( void ) const
{
    return this->name;
}

int                 Character::getAP( void ) const
{
    return this->ap;
}

AWeapon             *Character::getWeapon( void ) const
{
    return this->weapon;
}

/**
 * Others
 */

std::ostream    &operator << ( std::ostream & os, Character const & value )
{
    AWeapon *weapon = value.getWeapon();

    if (weapon != nullptr)
        os << value.getName() << " has " << value.getAP() << " AP and wields a " << weapon->getName() << std::endl;
    else
        os << value.getName() << " has " << value.getAP() << " AP and is unarmed" << std::endl;
    
    return os;
}
