/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:44:21 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:02:00 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

static std::string  randomName( void ) {
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    unsigned short  len = rand() % 13 + 4;
    std::string     str = std::string(len, '\0');

    for (int i = 0; i < len; ++i) {
        str[i] = alpha[rand() % (sizeof(alpha) - 1)];
    }

    return str;
}

ZombieHorde::ZombieHorde( int size )
{
    this->size = size;
    this->horde = new Zombie[size];

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        this->horde[i].setProps("zombie", randomName());
    }
}

ZombieHorde::~ZombieHorde( void )
{
    delete [] this->horde;
}

void    ZombieHorde::announce( void )
{
    for (int i = 0; i < this->size; i++)
    {
        this->horde[i].announce();
    }
}
