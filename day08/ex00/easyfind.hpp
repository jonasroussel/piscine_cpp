/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:14:54 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/24 14:25:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <list>
#include <exception>

template <typename T>
int		easyfind( T list, int value )
{
	try
	{
		std::list<int>::const_iterator  it = list.begin();

        for (int i = 0; it != list.end(); i++)
        {
			if (*it == value)
				return (i);
			it++;
        }
	}
	catch (std::exception& e)
	{
		throw std::exception();
	}
	
    throw std::exception();
}

#endif
