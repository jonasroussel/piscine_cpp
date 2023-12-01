/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:56:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/16 16:49:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

/**
 * Private Methods
 */

void            ScravTrap::blinded( void )
{
    std::cout << "SCR4V-TP " << getName() << " will try to kill the newcomer blinded" << std::endl;
}

void            ScravTrap::willBeKind( void )
{
    std::cout << "SCR4V-TP " << getName() << " will try to be kinded" << std::endl;
}

void            ScravTrap::fortniteTop1( void )
{
    std::cout << "SCR4V-TP " << getName() << " will try to a Fortnite Top 1" << std::endl;
}

/**
 * Constructors & Destructors
 */

ScravTrap::ScravTrap( void ) :
    hitPoints(100),
    maxHitPoints(100),
    energyPoints(50),
    maxEnergyPoints(50),
    level(1),
    name("SCR4V-TP"),
    meleeAttackDamage(20),
    rangedAttackDamage(15),
    armorDamageReduction(3)
{
    std::cout << "SCR4V-TP " << getName() << " has been created !" << std::endl;
    srand(time(NULL));
}

ScravTrap::ScravTrap( ScravTrap const & _value ) :
    hitPoints(_value.hitPoints),
    maxHitPoints(_value.maxHitPoints),
    energyPoints(_value.energyPoints),
    maxEnergyPoints(_value.maxEnergyPoints),
    level(_value.level),
    name(_value.name),
    meleeAttackDamage(_value.meleeAttackDamage),
    rangedAttackDamage(_value.rangedAttackDamage),
    armorDamageReduction(_value.armorDamageReduction)
{
    std::cout << "SCR4V-TP " << getName() << " has been cloned !" << std::endl;
    srand(time(NULL));
}

ScravTrap::ScravTrap( std::string _name ) :
    hitPoints(100),
    maxHitPoints(100),
    energyPoints(100),
    maxEnergyPoints(100),
    level(1),
    name(_name),
    meleeAttackDamage(20),
    rangedAttackDamage(15),
    armorDamageReduction(3)
{
    std::cout << "SCR4V-TP " << getName() << " has been created !" << std::endl;
    srand(time(NULL));
}

ScravTrap::~ScravTrap( void )
{
    std::cout << "SCR4V-TP " << getName() << " has been destroyed !" << std::endl;
}

/**
 * Operators
 */

ScravTrap & ScravTrap::operator = ( ScravTrap const & _value )
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

void            ScravTrap::rangedAttack( std::string const & target )
{
    std::cout << "SCR4V-TP " << getName() << " attacks " << target << " at range, causing " << getRangedAttackDamage()
        << " points of damage !" << std::endl;
}

void            ScravTrap::meleeAttack( std::string const & target )
{
    std::cout << "SCR4V-TP " << getName() << " attacks " << target << " at melee, causing " << getMeleeAttackDamage()
        << " points of damage !" << std::endl;
}

void            ScravTrap::takeDamage( unsigned int amount )
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

    std::cout << "SCR4V-TP " << getName() << " get attacks, causing " << realAmount << " points of damage !" << std::endl;
}

void            ScravTrap::beRepaired( unsigned int amount )
{
    if (getHitPoints() + amount > getMaxHitPoints())
        setHitPoints(getMaxHitPoints());
    else
        setHitPoints(getHitPoints() + amount);

    std::cout << "SCR4V-TP " << getName() << " has been repaired by " << amount << " !" << std::endl;
}

void            ScravTrap::challengeNewcomer( void )
{
    void (ScravTrap::*challenges[])( void ) =
	{
		&ScravTrap::blinded,
		&ScravTrap::willBeKind,
		&ScravTrap::fortniteTop1,
	};

	std::cout << "FR4G-TP " << getName() << " challenge the newcomer!" << std::endl;
	
	(this->*challenges[rand() % 3])();
}

/**
 * Getters
 */

unsigned int    ScravTrap::getHitPoints( void ) const
{
    return this->hitPoints;
}

unsigned int    ScravTrap::getMaxHitPoints( void ) const
{
    return this->maxHitPoints;
}

unsigned int    ScravTrap::getEnergyPoints( void ) const
{
    return this->energyPoints;
}

unsigned int    ScravTrap::getMaxEnergyPoints( void ) const
{
    return this->maxEnergyPoints;
}

unsigned int    ScravTrap::getLevel( void ) const
{
    return this->level;
}

std::string     ScravTrap::getName( void ) const
{
    return this->name;
}

unsigned int    ScravTrap::getMeleeAttackDamage( void ) const
{
    return this->meleeAttackDamage;
}

unsigned int    ScravTrap::getRangedAttackDamage( void ) const
{
    return this->rangedAttackDamage;
}

unsigned int    ScravTrap::getArmorDamageReduction( void ) const
{
    return this->armorDamageReduction;
}

/**
 * Setters
 */

void            ScravTrap::setHitPoints( unsigned int const & _value )
{
    this->hitPoints = _value;
}

void            ScravTrap::setMaxHitPoints( unsigned int const & _value )
{
    this->maxHitPoints = _value;
}

void            ScravTrap::setEnergyPoints( unsigned int const & _value )
{
    this->energyPoints = _value;
}

void            ScravTrap::setMaxEnergyPoints( unsigned int const & _value )
{
    this->maxEnergyPoints = _value;
}

void            ScravTrap::setLevel( unsigned int const & _value )
{
    this->level = _value;
}

void            ScravTrap::setName( std::string const & _value )
{
    this->name = _value;
}

void            ScravTrap::setMeleeAttackDamage( unsigned int const & _value )
{
    this->meleeAttackDamage = _value;
}

void            ScravTrap::setRangedAttackDamage( unsigned int const & _value )
{
    this->rangedAttackDamage = _value;
}

void            ScravTrap::setArmorDamageReduction( unsigned int const & _value )
{
    this->armorDamageReduction = _value;
}

