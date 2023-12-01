/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:47:34 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 15:31:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <string>
# include <iostream>

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist( void );
    PowerFist( PowerFist const & origin );
    ~PowerFist( void );

    PowerFist &operator = ( PowerFist const & value );

    void    attack( void ) const;
};

#endif
