/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:54:47 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:21:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{

private:
    Weapon*     weapon;
    std::string name;

public:
    HumanB( std::string name );
    ~HumanB( void );

    void    attack( void );

    void    setWeapon( Weapon& weapon );
};

#endif
