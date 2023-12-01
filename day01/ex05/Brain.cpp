/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:14:08 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:40:13 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( float mass, int iq )
{
    this->mass = mass;
    this->iq = iq;
}

Brain::Brain( void )
{
    this->mass = 250;
    this->iq = 21;
}

Brain::~Brain( void ) {}

std::string Brain::identify( void ) const
{
    std::stringstream   stream;

    stream << (void *)this;
    
    return stream.str();
}
