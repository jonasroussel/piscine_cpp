/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:40:11 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 15:53:01 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate( void )
{
    int rng = rand() % 3;

    if (rng == 0)
        return new A();
    else if (rng == 1)
        return new B();
    else
        return new C();
}

void identify_from_pointer( Base * base )
{
    if (dynamic_cast<A *>(base))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(base))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(base))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify_from_reference( Base & base )
{
    if (dynamic_cast<A *>(&base))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&base))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&base))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

int main( void )
{
    srand(time(NULL));

    Base * base = generate();
    Base * base2 = generate();

    identify_from_pointer(base);
    identify_from_reference(*base);

    delete base;

    std::cout << std::endl; 

    identify_from_pointer(base2);
    identify_from_reference(*base2);

    delete base2;

    return 0;
}
