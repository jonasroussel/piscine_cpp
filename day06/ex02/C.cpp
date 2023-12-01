/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:32:57 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 15:39:53 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

/**
 * Constructors & Destructor
 */

C::C( void ) {}

C::C( C const & val )
{
    (void)val;
}

C::~C( void ) {}

C   &C::operator = ( C const & val )
{
    (void)val;
    return *this;
}
