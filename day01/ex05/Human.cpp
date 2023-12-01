/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:29:04 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:48:19 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void ) {}

Human::~Human( void ) {}

std::string     Human::identify( void )
{
    return this->brain.identify();
}

const Brain&    Human::getBrain( void )
{
    return this->brain;
}
