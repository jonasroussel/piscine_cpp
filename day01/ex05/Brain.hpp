/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:10:25 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:40:07 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain
{

private:
    float   mass;
    int     iq;

public:
    Brain( void );
    Brain( float mass, int iq );
    ~Brain( void );

    std::string identify( void ) const;
};


#endif
