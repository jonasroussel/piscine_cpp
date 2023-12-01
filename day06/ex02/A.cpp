/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:32:57 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/22 15:35:58 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

/**
 * Constructors & Destructor
 */

A::A( void ) {}

A::A( A const & val )
{
    (void)val;
}

A::~A( void ) {}

A   &A::operator = ( A const & val )
{
    (void)val;
    return *this;
}
