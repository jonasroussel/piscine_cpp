/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:41:40 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 16:19:26 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScravTrap.hpp"

int main( int argc, char const *argv[] )
{
    FragTrap    bidule("Bidule");
    ScravTrap   truc("Truc");

    bidule.meleeAttack("Machin");
    bidule.takeDamage(15);
    bidule.beRepaired(5);
    bidule.rangedAttack("Machin");
    bidule.takeDamage(20);
    bidule.vaulthunter_dot_exe("Machin");

    truc.meleeAttack("An human");
    truc.takeDamage(15);
    truc.beRepaired(5);
    truc.rangedAttack("An human");
    truc.takeDamage(20);
    truc.challengeNewcomer();

    return 0;
}
