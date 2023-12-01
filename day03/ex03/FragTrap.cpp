/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:56:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 17:10:57 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * Private Methods
 */
void    FragTrap::explode( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " exploded! causing the death of " << target << std::endl;
    setHitPoints(0);
}

void    FragTrap::kiss( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " kissed " << target << " causing... LOVE in the world !" << std::endl;
}

void    FragTrap::trapped( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " trapped " << target << " causing " << getRangedAttackDamage() * 2
        << "  points of damage !" << std::endl;
}

void    FragTrap::metamorphe( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " metamorphosed " << target << " in duck !" << std::endl;
}

void    FragTrap::carbonize( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " carbonized " << target << " causing his death !" << std::endl;
}

/**
 * Constructors & Destructors
 */

FragTrap::FragTrap( void )
{
    setType("FR4G-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setMaxEnergyPoints(100);
    setLevel(1);
    setName("FR4G-TP");
    setMeleeAttackDamage(30);
    setRangedAttackDamage(20);
    setArmorDamageReduction(5);

    std::cout << "FR4G-TP " << getName() << " has been created !" << std::endl;
}

FragTrap::FragTrap( FragTrap const & _value )
{
    setType("FR4G-TP");
    setHitPoints(_value.getHitPoints());
    setMaxHitPoints(_value.getMaxHitPoints());
    setEnergyPoints(_value.getEnergyPoints());
    setMaxEnergyPoints(_value.getMaxEnergyPoints());
    setLevel(_value.getLevel());
    setName(_value.getName());
    setMeleeAttackDamage(_value.getMeleeAttackDamage());
    setRangedAttackDamage(_value.getRangedAttackDamage());
    setArmorDamageReduction(_value.getArmorDamageReduction());

    std::cout << "FR4G-TP " << getName() << " has been cloned !" << std::endl;
}

FragTrap::FragTrap( std::string _name )
{
    setType("FR4G-TP");
    setHitPoints(100);
    setMaxHitPoints(100);
    setEnergyPoints(100);
    setMaxEnergyPoints(100);
    setLevel(1);
    setName(_name);
    setMeleeAttackDamage(30);
    setRangedAttackDamage(20);
    setArmorDamageReduction(5);

    std::cout << "FR4G-TP " << getName() << " has been created !" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FR4G-TP " << getName() << " has been destroyed !" << std::endl;
}

/**
 * Operators
 */

FragTrap & FragTrap::operator = ( FragTrap const & _value )
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

/**
 * Public Methods
 */

void            FragTrap::vaulthunter_dot_exe( std::string const & target )
{
	void (FragTrap::*attacks[])(std::string const &) =
	{
		&FragTrap::explode,
		&FragTrap::kiss,
		&FragTrap::trapped,
		&FragTrap::metamorphe,
		&FragTrap::carbonize
	};

	if (getEnergyPoints() < 25)
	{
		std::cout << "FR4G-TP " << getName() << " does not have enough energy points!" << std::endl;
		return;
	}
	else
		setEnergyPoints(getEnergyPoints() - 25);
        
	std::cout << "FR4G-TP " << getName() << " uses vaulthunter.exe!" << std::endl;
	
	(this->*attacks[rand() % 5])(target);
	
    return;
}
