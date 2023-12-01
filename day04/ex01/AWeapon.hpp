/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:17:54 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:32:56 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{
protected:
    std::string name;
    int         apcost;
    int         damage;

public:
    AWeapon( void );
    AWeapon( std::string const & _name, int _apcost, int damage );
    AWeapon( AWeapon const & origin );
    ~AWeapon( void );

    AWeapon &operator = ( AWeapon const & value );

    virtual void    attack( void ) const = 0;

    std::string const   &getName( void ) const;
    int                 getAPCost( void ) const;
    int                 getDamage( void ) const;
};

#endif
