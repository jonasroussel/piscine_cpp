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

ScravTrap::ScravTrap( void )
{
    setType("SCR4V-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setMaxEnergyPoints(50);
    setLevel(1);
    setName("SCR4V-TP");
    setMeleeAttackDamage(20);
    setRangedAttackDamage(15);
    setArmorDamageReduction(3);

    std::cout << "SCR4V-TP " << getName() << " has been created !" << std::endl;
}

ScravTrap::ScravTrap( ScravTrap const & _value )
{
    setType("SCR4V-TP");
    setHitPoints(_value.getHitPoints());
    setMaxHitPoints(_value.getMaxHitPoints());
    setEnergyPoints(_value.getEnergyPoints());
    setMaxEnergyPoints(_value.getMaxEnergyPoints());
    setLevel(_value.getLevel());
    setName(_value.getName());
    setMeleeAttackDamage(_value.getMeleeAttackDamage());
    setRangedAttackDamage(_value.getRangedAttackDamage());
    setArmorDamageReduction(_value.getArmorDamageReduction());

    std::cout << "SCR4V-TP " << getName() << " has been cloned !" << std::endl;
}

ScravTrap::ScravTrap( std::string _name )
{
    setType("SCR4V-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setMaxEnergyPoints(50);
    setLevel(1);
    setName(_name);
    setMeleeAttackDamage(20);
    setRangedAttackDamage(15);
    setArmorDamageReduction(3);

    std::cout << "SCR4V-TP " << getName() << " has been created !" << std::endl;
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
    setHitPoints(_value.getHitPoints());
    setMaxHitPoints(_value.getMaxHitPoints());
    setEnergyPoints(_value.getEnergyPoints());
    setMaxEnergyPoints(_value.getMaxEnergyPoints());
    setLevel(_value.getLevel());
    setName(_value.getName());
    setMeleeAttackDamage(_value.getMeleeAttackDamage());
    setRangedAttackDamage(_value.getRangedAttackDamage());
    setArmorDamageReduction(_value.getArmorDamageReduction());
    return *this;
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

