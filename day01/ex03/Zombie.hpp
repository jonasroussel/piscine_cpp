/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:27:54 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 15:50:56 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

private:
    std::string name;
    std::string type;

public:
    Zombie( void );
    Zombie( std::string type, std::string name );
    ~Zombie( void );

    void    announce( void );

    void    setProps( std::string type, std::string name );
};

#endif
