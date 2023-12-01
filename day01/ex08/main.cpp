/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:40:45 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 12:53:22 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(int argc, char const *argv[])
{
    Human   human = Human();

    human.action("meleeAttack", "another human");
    human.action("intimidatingShout", "me");

    return 0;
}
