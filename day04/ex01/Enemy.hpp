/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:51:25 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 16:20:55 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
protected:
    int         hp;
    std::string type;

public:
    Enemy( void );
    Enemy( int _hp, std::string const & _type );
    Enemy( Enemy const & origin );
    virtual ~Enemy( void );

    Enemy   &operator = ( Enemy const & value );

    virtual void    takeDamage( int amount );

    int                 getHP( void ) const;
    std::string const   &getType( void ) const;
};

#endif
