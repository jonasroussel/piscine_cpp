/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:29:01 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 13:02:47 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony( std::string name, unsigned int age, std::string color )
{
    this->name = name;
    this->age = age;
    this->color = color;
}

Pony::~Pony( void ) {}

void            Pony::gallop( std::string where )
{
    std::cout << getName() << " gallop on the " << where <<  " !" << std::endl;
}

std::string     Pony::getName( void )
{
    return this->name;
}

unsigned int    Pony::getAge( void )
{
    return this->age;
}

std::string     Pony::getColor( void )
{
    return this->color;
}

void            Pony::setName( std::string name )
{
    this->name = name;
}

void            Pony::setAge( unsigned int age )
{
    this->age = age;
}

void            Pony::setColor( std::string color )
{
    this->color = color;
}
