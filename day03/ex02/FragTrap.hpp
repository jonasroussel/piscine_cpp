/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 16:45:11 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    void    explode( std::string const & target );
    void    kiss( std::string const & target );
    void    trapped( std::string const & target );
    void    metamorphe( std::string const & target );
    void    carbonize( std::string const & target );

public:
    FragTrap( void );
    FragTrap( FragTrap const & _value );
    FragTrap( std::string _name );
    ~FragTrap( void );
    
    FragTrap    &operator = ( FragTrap const & _value );

    void        vaulthunter_dot_exe( std::string const & target );
};

#endif
