/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:41:28 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:54:32 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <ctime>
# include "Zombie.hpp"

class ZombieHorde
{

private:
    int     size;
    Zombie* horde;

public:
    ZombieHorde( int size );
    ~ZombieHorde( void );

    void    announce( void );
};


#endif
