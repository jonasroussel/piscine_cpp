/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:29 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 15:27:21 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    static int const    NFB = 8;
    
    int                 fpv;

public:
    Fixed( void );
    Fixed( Fixed const & );
    Fixed & operator = ( Fixed const & );
    ~Fixed( void );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

#endif
