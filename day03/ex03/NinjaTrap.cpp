/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:56:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/16 16:49:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

/**
 * Private Methods
 */


/**
 * Constructors & Destructors
 */

NinjaTrap::NinjaTrap( void )
{
    setType("NINJ4-TP");
    setHitPoints(60);
    setMaxHitPoints(60);
    setEnergyPoints(120);
    setMaxEnergyPoints(120);
    setLevel(1);
    setName("NINJ4-TP");
    setMeleeAttackDamage(60);
    setRangedAttackDamage(5);
    setArmorDamageReduction(0);

    std::cout << "NINJ4-TP " << getName() << " has been created !" << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const & _value )
{
    setType("NINJ4-TP");
    setHitPoints(_value.getHitPoints());
    setMaxHitPoints(_value.getMaxHitPoints());
    setEnergyPoints(_value.getEnergyPoints());
    setMaxEnergyPoints(_value.getMaxEnergyPoints());
    setLevel(_value.getLevel());
    setName(_value.getName());
    setMeleeAttackDamage(_value.getMeleeAttackDamage());
    setRangedAttackDamage(_value.getRangedAttackDamage());
    setArmorDamageReduction(_value.getArmorDamageReduction());

    std::cout << "NINJ4-TP " << getName() << " has been cloned !" << std::endl;
}

NinjaTrap::NinjaTrap( std::string _name )
{
    setType("NINJ4-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(50);
    setMaxEnergyPoints(50);
    setLevel(1);
    setName(_name);
    setMeleeAttackDamage(20);
    setRangedAttackDamage(15);
    setArmorDamageReduction(3);

    std::cout << "NINJ4-TP " << getName() << " has been created !" << std::endl;
}

NinjaTrap::~NinjaTrap( void )
{
    std::cout << "NINJ4-TP " << getName() << " has been destroyed !" << std::endl;
}

/**
 * Operators
 */

NinjaTrap & NinjaTrap::operator = ( NinjaTrap const & _value )
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

void    NinjaTrap::ninjaShoebox( ClapTrap & target )
{
    std::cout << "NINJ4-TP " << getName() << " attacked " << target.getType() << " " << target.getName() << " !" << std::endl;
}

void    NinjaTrap::ninjaShoebox( FragTrap & target )
{
    std::cout << "NINJ4-TP " << getName() << " attacked " << target.getType() << " " << target.getName() << " !" << std::endl;
}

void    NinjaTrap::ninjaShoebox( ScravTrap & target )
{
    std::cout << "NINJ4-TP " << getName() << " attacked " << target.getType() << " " << target.getName() << " !" << std::endl;
}

void    NinjaTrap::ninjaShoebox( NinjaTrap & target )
{
    std::cout << "NINJ4-TP " << getName() << " attacked " << target.getType() << " " << target.getName() << " !" << std::endl;
}

