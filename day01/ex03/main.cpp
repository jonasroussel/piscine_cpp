/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:32:50 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:01:08 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main( void )
{
    ZombieHorde*    zh = new ZombieHorde(10);

    zh->announce();

    delete zh;

    return 0;
}
