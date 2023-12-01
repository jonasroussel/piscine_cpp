/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:56:55 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:27:56 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

/**
 * Constructors & Destructor
 */

Enemy::Enemy(
    int _hp,
    std::string const & _type
):
    hp(_hp),
    type(_type)
{}

Enemy::Enemy( Enemy const & origin ) :
    hp(origin.hp),
    type(origin.type)
{}

Enemy::~Enemy( void ) {}

/**
 * Operators
 */

Enemy   &Enemy::operator = ( Enemy const & value )
{
    this->hp = value.hp;
    this->type = value.type;
    return *this;
}

/**
 * Public Methods
 */

void    Enemy::takeDamage( int amount )
{
    if (amount == 0)
        return;

    if (getHP() - amount <= 0)
        this->hp = 0;
    else
        this->hp -= amount;
}

/**
 * Getters & Setters
 */

int                 Enemy::getHP( void ) const
{
    return this->hp;
}

std::string const   &Enemy::getType( void ) const
{
    return this->type;
}
