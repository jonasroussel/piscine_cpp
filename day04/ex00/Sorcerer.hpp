/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:17:57 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 13:19:02 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "Victim.hpp"

class Sorcerer
{
private:
    std::string name;
    std::string title;
    
public:
    Sorcerer( void );
    Sorcerer( std::string _name, std::string _title );
    Sorcerer( Sorcerer const & _value );
    ~Sorcerer( void );

    Sorcerer    &operator = ( Sorcerer const & _value );    

    void    polymorph( Victim const & victim ) const;

    std::string getName( void ) const;
    std::string getTitle( void ) const;
};

std::ostream    &operator << ( std::ostream & os, Sorcerer const & _value ); 

#endif
