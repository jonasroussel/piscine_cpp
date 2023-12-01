/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:23:09 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 16:04:06 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->fpv = 0;
}

Fixed::Fixed( Fixed const & fixed )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed & Fixed::operator = ( Fixed const & fixed )
{
    std::cout << "Assignation operator called" << std::endl;
    this->fpv = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpv;
}

void    Fixed::setRawBits( int const raw )
{
    this->fpv = raw;
}
