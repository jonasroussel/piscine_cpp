/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:29 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 15:57:26 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed
{
private:
    static int const    NFB = 8;
    
    int                 value;

public:
    Fixed( void );
    Fixed( Fixed const & );
    Fixed( int const );
    Fixed ( float const );
    
    Fixed & operator = ( Fixed const & );
    
    ~Fixed( void );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream & operator << (std::ostream & os, Fixed const & fixed);

#endif
