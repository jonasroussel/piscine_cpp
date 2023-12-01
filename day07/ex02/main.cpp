/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:34:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/24 14:07:52 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main( void )
{
    Array<int> ints(2);

    ints[0] = 4;
    ints[1] = 2;

    std::cout << ints[0] << ints[1] << std::endl;

    try
    {
        ints[2];
    }
    catch (std::exception & ex)
    {
        std::cout << "error" << std::endl;
    }

    return 0;
}
