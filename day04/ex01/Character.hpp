/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:33:37 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:02:54 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
    std::string name;
    int         ap;
    AWeapon     *weapon;

public:
    Character( void );
    Character( std::string const & _name );
    Character( Character const & origin );
    ~Character( void );

    Character   &operator = ( Character const & value );

    void    recoverAP( void );
    void    equip( AWeapon * weapon );
    void    attack( Enemy * enemy );

    std::string const   &getName( void ) const;
    int                 getAP( void ) const;
    AWeapon             *getWeapon( void ) const;
};

std::ostream    &operator << ( std::ostream & os, Character const & value );

#endif
