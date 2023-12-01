/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:27:39 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/14 16:45:38 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{

private:
    const Brain brain;

public:
    Human( void );
    ~Human( void );

    std::string     identify( void );

    const Brain&    getBrain( void );
};

#endif
