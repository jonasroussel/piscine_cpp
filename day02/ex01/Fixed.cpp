/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:23:09 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 17:14:49 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & fixed )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed( int const _value )
{
    std::cout << "Int constructor called" << std::endl;
    this->value = _value << NFB;
}

Fixed::Fixed( float const _value )
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(_value * (1 << NFB));
}

Fixed & Fixed::operator = ( Fixed const & fixed )
{
    std::cout << "Assignation operator called" << std::endl;
    this->value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return this->value;
}

void    Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float   Fixed::toFloat( void ) const
{
    return (float)this->value / (1 << NFB);
}

int     Fixed::toInt( void ) const
{
    return this->value >> NFB;
}

std::ostream & operator << (std::ostream & os, Fixed const & fixed)
{
    os << fixed.toFloat();
    return os;
}
