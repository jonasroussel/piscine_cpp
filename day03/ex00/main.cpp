/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:41:40 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/16 16:51:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( int argc, char const *argv[] )
{
    FragTrap bidule("Bidule");

    bidule.meleeAttack("Machin");
    bidule.takeDamage(15);
    bidule.beRepaired(5);
    bidule.rangedAttack("Machin");
    bidule.takeDamage(20);
    bidule.vaulthunter_dot_exe("Machin");

    return 0;
}
