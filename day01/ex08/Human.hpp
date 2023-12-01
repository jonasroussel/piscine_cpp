/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:21:59 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 12:45:52 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <iostream>
# include <map>


class Human
{
private:
    typedef void (Human::*Attack)( std::string const & );
    
    std::map<std::string const, Human::Attack>  attacks;

    void    meleeAttack( std::string const & target );
    void    rangedAttack( std::string const & target );
    void    intimidatingShout( std::string const & target );

public:
    Human( void );
    ~Human( void );

    void    action( std::string const & action_name, std::string const & target );
};

#endif
