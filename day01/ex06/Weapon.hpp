/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:51:03 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 17:11:30 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{

private:
    std::string type;

public:
    Weapon( std::string type );
    Weapon( void );
    ~Weapon( void );

    const std::string&  getType( void );
    void                setType( std::string type );
};

#endif
