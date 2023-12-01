/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:36:45 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 15:31:46 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <string>
# include <iostream>

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle( void );
    PlasmaRifle( PlasmaRifle const & origin );
    ~PlasmaRifle( void );

    PlasmaRifle &operator = ( PlasmaRifle const & value );

    void    attack( void ) const;
};

#endif
