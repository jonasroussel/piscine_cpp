/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:37:02 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:39:04 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

static std::string  randomString( void ) {
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    unsigned short  len = rand() % 13 + 4;
    std::string     str = std::string(len, '\0');

    for (int i = 0; i < len; ++i) {
        str[i] = alpha[rand() % (sizeof(alpha) - 1)];
    }

    return str;
}

ZombieEvent::ZombieEvent( void )
{
    this->type = std::string();

    srand(time(NULL));
}

ZombieEvent::~ZombieEvent( void ) {}

void    ZombieEvent::setZombieType( std::string type )
{
    this->type = type;
}

Zombie* ZombieEvent::newZombie( std::string name )
{
    return new Zombie(this->type, name);
}

void    ZombieEvent::randomChump( void )
{
    Zombie zombie = Zombie(this->type, randomString());
    zombie.announce();
}
