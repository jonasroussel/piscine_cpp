/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:02:49 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:07:02 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    ptr = &str;
    std::string&    ref = str;

    std::cout << "Original string: " << str << std::endl;
    std::cout << "String from pointer: " << *ptr << std::endl;
    std::cout << "String from reference: " << ref << std::endl;

    return 0;
}
