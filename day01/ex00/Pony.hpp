/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:28:38 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 13:01:20 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{

private:
    std::string     name;
    unsigned int    age;
    std::string     color;

public:
    Pony( std::string name, unsigned int age, std::string color );
    ~Pony( void );

    void            gallop( std::string where );

    std::string     getName( void );
    unsigned int    getAge( void );
    std::string     getColor( void );

    void            setName( std::string name );
    void            setAge( unsigned int age );
    void            setColor( std::string color );
};

#endif
