/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/16 16:45:18 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

class FragTrap
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

    void    explode( std::string const & target );
    void    kiss( std::string const & target );
    void    trapped( std::string const & target );
    void    metamorphe( std::string const & target );
    void    carbonize( std::string const & target );

public:
    FragTrap( void );
    FragTrap( FragTrap const & _value );
    FragTrap( std::string _name );
    ~FragTrap( void );
    
    FragTrap & operator = ( FragTrap const & _value );

    void            rangedAttack( std::string const & target );
    void            meleeAttack( std::string const & target );
    void            takeDamage( unsigned int amount );
    void            beRepaired( unsigned int amount );
    void            vaulthunter_dot_exe( std::string const & target );

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
