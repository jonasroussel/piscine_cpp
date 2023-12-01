/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:54:47 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:21:13 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{

private:
    Weapon&     weapon;
    std::string name;

public:
    HumanA( std::string name, Weapon& weapon );
    ~HumanA( void );

    void    attack( void );
};

#endif
