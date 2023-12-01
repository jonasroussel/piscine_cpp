/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:07:23 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:27:06 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <string>
# include <iostream>

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
    SuperMutant( void );
    SuperMutant( SuperMutant const & origin );
    ~SuperMutant( void );

    SuperMutant &operator = ( SuperMutant const & value );

    void    takeDamage( int amount );
};

#endif
