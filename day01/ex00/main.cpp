/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:25:25 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 13:01:59 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Pony.hpp"

static void ponyOnTheHeap( void )
{
    Pony    *pp = new Pony("Pinkie Pie", 4, "Pink");
    pp->gallop("heap");
    delete pp;
}

static void ponyOnTheStack( void )
{
    Pony    rd = Pony("Rainbow Dash", 4, "Blue");
    rd.gallop("stack");
}

int         main( void )
{
    ponyOnTheHeap();
    ponyOnTheStack();
    return 0;
}
