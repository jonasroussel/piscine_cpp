/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:56:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 16:54:11 by jroussel         ###   ########.fr       */
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

FragTrap::FragTrap( void ) :
    hitPoints(100),
    maxHitPoints(100),
    energyPoints(100),
    maxEnergyPoints(100),
    level(1),
    name("FR4G-TP"),
    meleeAttackDamage(30),
    rangedAttackDamage(20),
    armorDamageReduction(5)
{
    std::cout << "FR4G-TP " << getName() << " has been created !" << std::endl;
    srand(time(NULL));
}

FragTrap::FragTrap( FragTrap const & _value ) :
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
    std::cout << "FR4G-TP " << getName() << " has been cloned !" << std::endl;
    srand(time(NULL));
}

FragTrap::FragTrap( std::string _name ) :
    hitPoints(100),
    maxHitPoints(100),
    energyPoints(100),
    maxEnergyPoints(100),
    level(1),
    name(_name),
    meleeAttackDamage(30),
    rangedAttackDamage(20),
    armorDamageReduction(5)
{
    std::cout << "FR4G-TP " << getName() << " has been created !" << std::endl;
    srand(time(NULL));
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

void            FragTrap::rangedAttack( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " attacks " << target << " at range, causing " << getRangedAttackDamage()
        << " points of damage !" << std::endl;
}

void            FragTrap::meleeAttack( std::string const & target )
{
    std::cout << "FR4G-TP " << getName() << " attacks " << target << " at melee, causing " << getMeleeAttackDamage()
        << " points of damage !" << std::endl;
}

void            FragTrap::takeDamage( unsigned int amount )
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

    std::cout << "FR4G-TP " << getName() << " get attacks, causing " << realAmount << " points of damage !" << std::endl;
}

void            FragTrap::beRepaired( unsigned int amount )
{
    if (getHitPoints() + amount > getMaxHitPoints())
        setHitPoints(getMaxHitPoints());
    else
        setHitPoints(getHitPoints() + amount);

    std::cout << "FR4G-TP " << getName() << " has been repaired by " << amount << " !" << std::endl;
}

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

/**
 * Getters
 */

unsigned int    FragTrap::getHitPoints( void ) const
{
    return this->hitPoints;
}

unsigned int    FragTrap::getMaxHitPoints( void ) const
{
    return this->maxHitPoints;
}

unsigned int    FragTrap::getEnergyPoints( void ) const
{
    return this->energyPoints;
}

unsigned int    FragTrap::getMaxEnergyPoints( void ) const
{
    return this->maxEnergyPoints;
}

unsigned int    FragTrap::getLevel( void ) const
{
    return this->level;
}

std::string     FragTrap::getName( void ) const
{
    return this->name;
}

unsigned int    FragTrap::getMeleeAttackDamage( void ) const
{
    return this->meleeAttackDamage;
}

unsigned int    FragTrap::getRangedAttackDamage( void ) const
{
    return this->rangedAttackDamage;
}

unsigned int    FragTrap::getArmorDamageReduction( void ) const
{
    return this->armorDamageReduction;
}

/**
 * Setters
 */

void            FragTrap::setHitPoints( unsigned int const & _value )
{
    this->hitPoints = _value;
}

void            FragTrap::setMaxHitPoints( unsigned int const & _value )
{
    this->maxHitPoints = _value;
}

void            FragTrap::setEnergyPoints( unsigned int const & _value )
{
    this->energyPoints = _value;
}

void            FragTrap::setMaxEnergyPoints( unsigned int const & _value )
{
    this->maxEnergyPoints = _value;
}

void            FragTrap::setLevel( unsigned int const & _value )
{
    this->level = _value;
}

void            FragTrap::setName( std::string const & _value )
{
    this->name = _value;
}

void            FragTrap::setMeleeAttackDamage( unsigned int const & _value )
{
    this->meleeAttackDamage = _value;
}

void            FragTrap::setRangedAttackDamage( unsigned int const & _value )
{
    this->rangedAttackDamage = _value;
}

void            FragTrap::setArmorDamageReduction( unsigned int const & _value )
{
    this->armorDamageReduction = _value;
}

