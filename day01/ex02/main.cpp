/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:32:50 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:38:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main( void )
{
    Zombie  zombie1 = Zombie("boxer", "zombie1");
    zombie1.announce();

    ZombieEvent ze = ZombieEvent();

    ze.setZombieType("vegan");

    ze.randomChump();

    ze.setZombieType("crawler");

    Zombie* zombie2 = ze.newZombie("zombie2");
    zombie2->announce();

    delete zombie2;

    return 0;
}
