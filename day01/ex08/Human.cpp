/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:23:26 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 12:52:42 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void    Human::meleeAttack( std::string const & target )
{
    std::cout << "An human used a melee attack on " << target << std::endl;
}

void    Human::rangedAttack( std::string const & target )
{
    std::cout << "An human used a ranged attack on " << target << std::endl;
}

void    Human::intimidatingShout( std::string const & target )
{
    std::cout << "An human intimidating " << target << " with a shout" << std::endl;
}

Human::Human( void )
{
    attacks["meleeAttack"] = &Human::meleeAttack;
    attacks["rangedAttack"] = &Human::rangedAttack;
    attacks["intimidatingShout"] = &Human::intimidatingShout;
}

Human::~Human( void ) {}

void    Human::action( std::string const & action_name,
                       std::string const & target )
{
    if (this->attacks.find(action_name) != this->attacks.end())
    {
        (this->*attacks[action_name])( target );
    }   
}
