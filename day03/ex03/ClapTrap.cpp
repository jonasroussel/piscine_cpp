/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:24:28 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 11:30:16 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * Constructors & Destructors
 */

ClapTrap::ClapTrap( void ) : type("CL4P-TP")
{
    srand(time(NULL));
}

ClapTrap::ClapTrap( ClapTrap const & _value ) : type("CL4P-TP")
{
    srand(time(NULL));
}

ClapTrap::ClapTrap( std::string _name ) : type("CL4P-TP")
{
    srand(time(NULL));
}

ClapTrap::~ClapTrap( void ) {}

/**
 * Operators
 */

ClapTrap & ClapTrap::operator = ( ClapTrap const & _value )
{
    this->hitPoints = _value.hitPoints;
    this->maxHitPoints = _value.maxHitPoints;
    this->energyPoints = _value.energyPoints;
    this->maxEnergyPoints = _value.maxEnergyPoints;
    this->level = _value.level;
    this->name = _value.name;
    this->meleeAttackDamage = _value.meleeAttackDamage;
    this->rangedAttackDamage = _value.rangedAttackDamage;
    this->armorDamageReduction = _value.armorDamageReduction;
    return *this;
}

/**
 * Public Methods
 */

void            ClapTrap::rangedAttack( std::string const & target )
{
    std::cout << getType() << " " << getName() << " attacks " << target << " at range, causing " << getRangedAttackDamage()
        << " points of damage !" << std::endl;
}

void            ClapTrap::meleeAttack( std::string const & target )
{
    std::cout << getType() << " " << getName() << " attacks " << target << " at melee, causing " << getMeleeAttackDamage()
        << " points of damage !" << std::endl;
}

void            ClapTrap::takeDamage( unsigned int amount )
{
    unsigned int    realAmount = amount;

    if (realAmount < getArmorDamageReduction())
        realAmount = 0;
    else
        realAmount -= getArmorDamageReduction();

    if (getHitPoints() - realAmount < 0)
        setHitPoints(0);
    else
        setHitPoints(getHitPoints() - realAmount);

    std::cout << getType() << " " << getName() << " get attacks, causing " << realAmount << " points of damage !" << std::endl;
}

void            ClapTrap::beRepaired( unsigned int amount )
{
    if (getHitPoints() + amount > getMaxHitPoints())
        setHitPoints(getMaxHitPoints());
    else
        setHitPoints(getHitPoints() + amount);

    std::cout << getType() << " " << getName() << " has been repaired by " << amount << " !" << std::endl;
}

/**
 * Getters
 */

std::string     ClapTrap::getType( void ) const
{
    return this->type;
}

unsigned int    ClapTrap::getHitPoints( void ) const
{
    return this->hitPoints;
}

unsigned int    ClapTrap::getMaxHitPoints( void ) const
{
    return this->maxHitPoints;
}

unsigned int    ClapTrap::getEnergyPoints( void ) const
{
    return this->energyPoints;
}

unsigned int    ClapTrap::getMaxEnergyPoints( void ) const
{
    return this->maxEnergyPoints;
}

unsigned int    ClapTrap::getLevel( void ) const
{
    return this->level;
}

std::string     ClapTrap::getName( void ) const
{
    return this->name;
}

unsigned int    ClapTrap::getMeleeAttackDamage( void ) const
{
    return this->meleeAttackDamage;
}

unsigned int    ClapTrap::getRangedAttackDamage( void ) const
{
    return this->rangedAttackDamage;
}

unsigned int    ClapTrap::getArmorDamageReduction( void ) const
{
    return this->armorDamageReduction;
}

/**
 * Setters
 */

void            ClapTrap::setType( std::string const & _value )
{
    this->type = _value;
}

void            ClapTrap::setHitPoints( unsigned int const & _value )
{
    this->hitPoints = _value;
}

void            ClapTrap::setMaxHitPoints( unsigned int const & _value )
{
    this->maxHitPoints = _value;
}

void            ClapTrap::setEnergyPoints( unsigned int const & _value )
{
    this->energyPoints = _value;
}

void            ClapTrap::setMaxEnergyPoints( unsigned int const & _value )
{
    this->maxEnergyPoints = _value;
}

void            ClapTrap::setLevel( unsigned int const & _value )
{
    this->level = _value;
}

void            ClapTrap::setName( std::string const & _value )
{
    this->name = _value;
}

void            ClapTrap::setMeleeAttackDamage( unsigned int const & _value )
{
    this->meleeAttackDamage = _value;
}

void            ClapTrap::setRangedAttackDamage( unsigned int const & _value )
{
    this->rangedAttackDamage = _value;
}

void            ClapTrap::setArmorDamageReduction( unsigned int const & _value )
{
    this->armorDamageReduction = _value;
}
