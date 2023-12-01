/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:29:37 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:37:24 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string type, std::string name )
{
    this->type = type;
    this->name = name;   
}

Zombie::~Zombie( void ) {}

void    Zombie::announce( void )
{
    std::string screem = this->type == "vegan" ? "Vegeeetaableeeee" : "Braiiiiiiinnnssss";

    std::cout << "<" << this->name << " (" << this->type << ")> " << screem << "..." << std::endl;
}
