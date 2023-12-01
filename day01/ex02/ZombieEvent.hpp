/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:34:40 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:31:49 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <ctime>
# include "Zombie.hpp"

class ZombieEvent
{

private:
    std::string type;

public:
    ZombieEvent( void );
    ~ZombieEvent( void );

    void    setZombieType( std::string type );
    Zombie* newZombie( std::string name );
    void    randomChump( void );
};

#endif
