/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:41:40 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 12:04:40 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScravTrap.hpp"
#include "NinjaTrap.hpp"

int main( int argc, char const *argv[] )
{
    FragTrap    bidule("Machin");
    ScravTrap   truc("Truc");
    NinjaTrap   machin("Bidule");

    bidule.meleeAttack("a vaulthunder");
    bidule.takeDamage(15);
    bidule.beRepaired(5);
    bidule.rangedAttack("a vaulthunder");
    bidule.takeDamage(20);
    bidule.vaulthunter_dot_exe("a vaulthunder");

    truc.meleeAttack("a vaulthunder");
    truc.takeDamage(15);
    truc.beRepaired(5);
    truc.rangedAttack("a vaulthunder");
    truc.takeDamage(20);
    truc.challengeNewcomer();

    machin.meleeAttack("a vaulthunder");
    machin.takeDamage(15);
    machin.beRepaired(5);
    machin.rangedAttack("a vaulthunder");
    machin.takeDamage(20);
    machin.ninjaShoebox(bidule);
    machin.ninjaShoebox(truc);

    return 0;
}
