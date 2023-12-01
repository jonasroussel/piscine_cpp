/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:30:42 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:27:02 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <string>
# include <iostream>

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
    RadScorpion( void );
    RadScorpion( RadScorpion const & origin );
    ~RadScorpion( void );

    RadScorpion &operator = ( RadScorpion const & value );
};


#endif
