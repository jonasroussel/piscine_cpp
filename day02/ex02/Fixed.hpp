/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:29 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 17:27:43 by jroussel         ###   ########.fr       */
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
    
    ~Fixed( void );

    Fixed               &operator = ( Fixed const & );
    
    bool                operator > ( Fixed const & );
    bool                operator < ( Fixed const & );
    bool                operator >= ( Fixed const & );
    bool                operator <= ( Fixed const & );
    bool                operator == ( Fixed const & );
    bool                operator != ( Fixed const & );
    
    Fixed               operator + ( Fixed const & );
    Fixed               operator - ( Fixed const & );
    Fixed               operator * ( Fixed const & );
    Fixed               operator / ( Fixed const & );

    Fixed               &operator ++ ( void );
    Fixed               operator ++ ( int );
    Fixed               &operator -- ( void );
    Fixed               operator -- ( int );

    static Fixed        &min(Fixed & f1, Fixed & f2);
    static Fixed        &max(Fixed & f1, Fixed & f2);
    static Fixed const  &min(Fixed const & f1, Fixed const & f2);
    static Fixed const  &max(Fixed const & f1, Fixed const & f2);
    
    int                 getRawBits( void ) const;
    void                setRawBits( int const );
    
    float               toFloat( void ) const;
    int                 toInt( void ) const;
};

std::ostream & operator << (std::ostream & os, Fixed const & fixed);

#endif
