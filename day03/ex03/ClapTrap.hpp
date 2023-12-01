/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:22:01 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 17:04:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

class ClapTrap
{
private:
    std::string     type;
    unsigned int    hitPoints;
    unsigned int    maxHitPoints;
    unsigned int    energyPoints;
    unsigned int    maxEnergyPoints;
    unsigned int    level;
    std::string     name;
    unsigned int    meleeAttackDamage;
    unsigned int    rangedAttackDamage;
    unsigned int    armorDamageReduction;

public:
    ClapTrap( void );
    ClapTrap( ClapTrap const & _value );
    ClapTrap( std::string _name );
    ~ClapTrap( void );
    
    ClapTrap        &operator = ( ClapTrap const & _value );

    void            rangedAttack( std::string const & target );
    void            meleeAttack( std::string const & target );
    void            takeDamage( unsigned int amount );
    void            beRepaired( unsigned int amount );

    std::string     getType( void ) const;
    unsigned int    getHitPoints( void ) const;
    unsigned int    getMaxHitPoints( void ) const;
    unsigned int    getEnergyPoints( void ) const;
    unsigned int    getMaxEnergyPoints( void ) const;
    unsigned int    getLevel( void ) const;
    std::string     getName( void ) const;
    unsigned int    getMeleeAttackDamage( void ) const;
    unsigned int    getRangedAttackDamage( void ) const;
    unsigned int    getArmorDamageReduction( void ) const;

    void            setType( std::string const & _value );
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
