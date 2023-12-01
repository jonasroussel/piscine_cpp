/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 16:14:46 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

class ScravTrap
{
private:
    unsigned int    hitPoints;
    unsigned int    maxHitPoints;
    unsigned int    energyPoints;
    unsigned int    maxEnergyPoints;
    unsigned int    level;
    std::string     name;
    unsigned int    meleeAttackDamage;
    unsigned int    rangedAttackDamage;
    unsigned int    armorDamageReduction;

    void            blinded( void );
    void            willBeKind( void );
    void            fortniteTop1( void );

public:
    ScravTrap( void );
    ScravTrap( ScravTrap const & _value );
    ScravTrap( std::string _name );
    ~ScravTrap( void );
    
    ScravTrap & operator = ( ScravTrap const & _value );

    void            rangedAttack( std::string const & target );
    void            meleeAttack( std::string const & target );
    void            takeDamage( unsigned int amount );
    void            beRepaired( unsigned int amount );
    void            challengeNewcomer( void );

    unsigned int    getHitPoints( void ) const;
    unsigned int    getMaxHitPoints( void ) const;
    unsigned int    getEnergyPoints( void ) const;
    unsigned int    getMaxEnergyPoints( void ) const;
    unsigned int    getLevel( void ) const;
    std::string     getName( void ) const;
    unsigned int    getMeleeAttackDamage( void ) const;
    unsigned int    getRangedAttackDamage( void ) const;
    unsigned int    getArmorDamageReduction( void ) const;

    void            setHitPoints( unsigned int const & _value );
    void            setMaxHitPoints( unsigned int const & _value );
    void            setEnergyPoints( unsigned int const & _value );
    void            setMaxEnergyPoints( unsigned int const & _value );
    void            setLevel( unsigned int const & _value );
    void            setName( std::string const & _value );
    void            setMeleeAttackDamage( unsigned int const & _value );
    void            setRangedAttackDamage( unsigned int const & _value );
    void            setArmorDamageReduction( unsigned int const & _value );
};

#endif
