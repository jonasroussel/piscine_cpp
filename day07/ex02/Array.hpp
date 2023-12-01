/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:19:31 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/24 14:05:23 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
private:
    T*              data;
    unsigned int    length;

public:
    Array<T>( void ) : data(nullptr), length(0) {}

    Array<T>( unsigned int _length ) : length(_length)
    {
        this->data = new T[_length];
    }
    
    Array<T>( Array<T> const & v ) : data(v.data), length(v.length) {}
    
    ~Array<T>( void )
    {
        delete [] data;
    }

    Array<T>    &operator = ( Array<T> const & v )
    {
        this->length = v.length;
        delete [] this->data;
        this->data = new T[this->length];
        for (int i = 0; i < this->length; i++)
            this->data[i] = v.data[i];
        return *this;
    }
    
    T           &operator [] ( unsigned int index )
    {
        if (index >= this->length)
            throw std::exception();
        return this->data[index];
    }

    unsigned int    size( void )
    {
        return this->length;
    }
};

#endif
