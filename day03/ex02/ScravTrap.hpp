/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:36 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/17 17:14:53 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

# include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{
private:
    void            blinded( void );
    void            willBeKind( void );
    void            fortniteTop1( void );

public:
    ScravTrap( void );
    ScravTrap( ScravTrap const & _value );
    ScravTrap( std::string _name );
    ~ScravTrap( void );
    
    ScravTrap   &operator = ( ScravTrap const & _value );

    void        challengeNewcomer( void );
};

#endif
