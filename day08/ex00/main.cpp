/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:17:39 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/24 14:26:05 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "easyfind.hpp"

int main( void )
{
    std::list<int> lst;

    lst.push_back(4);
    lst.push_back(0);
    lst.push_back(8);
    lst.push_back(2);
    lst.push_back(7);

    std::cout << easyfind(lst, 4) << std::endl;
    std::cout << easyfind(lst, 2) << std::endl;

    return 0;
}
