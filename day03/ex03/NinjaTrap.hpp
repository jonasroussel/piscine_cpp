/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/18 12:00:01 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScravTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
    NinjaTrap( void );
    NinjaTrap( NinjaTrap const & _value );
    NinjaTrap( std::string _name );
    ~NinjaTrap( void );
    
    NinjaTrap   &operator = ( NinjaTrap const & _value );

    void        ninjaShoebox( ClapTrap & target );
    void        ninjaShoebox( FragTrap & target );
    void        ninjaShoebox( ScravTrap & target );
    void        ninjaShoebox( NinjaTrap & target );
};

#endif
