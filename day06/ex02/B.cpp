/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:32:57 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 15:39:03 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

/**
 * Constructors & Destructor
 */

B::B( void ) {}

B::B( B const & val )
{
    (void)val;
}

B::~B( void ) {}

B   &B::operator = ( B const & val )
{
    (void)val;
    return *this;
}
