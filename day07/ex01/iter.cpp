/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:00:44 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/24 13:15:06 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void    SAY(T & v)
{
    std::cout << v << std::endl;
}

template <typename T>
void    iter(T * arr, size_t len, void (*fn)(T &))
{
    for (size_t i = 0; i < len; i++)
        fn(arr[i]);
}

int main( void )
{
    std::string	strings[] = { "A", "B", "C", "D" };
	char	chars[] = { 'A', 'B', 'C', 'D' };
	int 	ints[] = { 0, 1, 2, 3 };

    std::cout << "strings: " << std::endl;
    iter<std::string>(strings, 4, SAY);

    std::cout << "chars: " << std::endl;
    iter<char>(chars, 4, SAY);

    std::cout << "ints: " << std::endl;
    iter<int>(ints, 4, SAY);

    return 0;
}
