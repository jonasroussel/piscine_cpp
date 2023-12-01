/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:23:09 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 17:39:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0) {}
Fixed::Fixed( Fixed const & fixed )
{
    *this = fixed;
}

Fixed::Fixed( int const _value ) : value(_value << NFB) {}
Fixed::Fixed( float const _value ) : value(roundf(_value * (1 << NFB))) {}

Fixed::~Fixed( void ) {}

Fixed & Fixed::operator = ( Fixed const & fixed )
{
    this->value = fixed.getRawBits();
    return *this;
}

bool    Fixed::operator > ( Fixed const & fixed )
{
    return (this->toFloat() > fixed.toFloat());
}
bool    Fixed::operator < ( Fixed const & fixed )
{
    return (this->toFloat() < fixed.toFloat());
}
bool    Fixed::operator >= ( Fixed const & fixed )
{
    return (this->toFloat() >= fixed.toFloat());
}
bool    Fixed::operator <= ( Fixed const & fixed )
{
    return (this->toFloat() >= fixed.toFloat());
}
bool    Fixed::operator == ( Fixed const & fixed )
{
    return (this->toFloat() == fixed.toFloat());
}
bool    Fixed::operator != ( Fixed const & fixed )
{
    return (this->toFloat() != fixed.toFloat());
}

Fixed   Fixed::operator + ( Fixed const & fixed )
{
	return Fixed(this->value + fixed.getRawBits());
}
Fixed   Fixed::operator - ( Fixed const & fixed )
{
	return Fixed(this->value - fixed.getRawBits());
}
Fixed   Fixed::operator * ( Fixed const & fixed )
{
	return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed   Fixed::operator / ( Fixed const & fixed )
{
	if (fixed.toFloat() != 0)
	{
        return Fixed(this->toFloat() / fixed.toFloat());
    }
    else
	{
		std::cout << "error: Cannot divide by 0" << std::endl;
		return Fixed(0);
	}
}

Fixed & Fixed::operator ++ ( void )
{
	this->value += 1;
	return *this;
}
Fixed   Fixed::operator ++ ( __attribute__((unused)) int _value )
{
	Fixed prev(*this);

	this->value += 1;
	return prev;
}
Fixed & Fixed::operator -- ( void )
{
	this->value -= 1;
	return *this;
}
Fixed   Fixed::operator -- ( __attribute__((unused)) int _value )
{
	Fixed prev(*this);

	this->value -= 1;
	return (prev);
}

Fixed           &Fixed::min( Fixed & f1, Fixed & f2 )
{
	return ((f1.toFloat() < f2.toFloat()) ? f1 : f2);
}
Fixed           &Fixed::max( Fixed & f1, Fixed & f2 )
{
	return ((f1.toFloat() > f2.toFloat()) ? f1 : f2);
}
Fixed const     &Fixed::min(Fixed const & f1, Fixed const & f2 )
{
	return ((f1.toFloat() < f2.toFloat()) ? f1 : f2);
}
Fixed const     &Fixed::max( Fixed const & f1, Fixed const & f2 )
{
	return ((f1.toFloat() > f2.toFloat()) ? f1 : f2);
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
