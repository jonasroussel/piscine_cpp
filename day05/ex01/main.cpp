/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:57:33 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/21 15:18:08 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat a("Cedric Page", 1);
    Bureaucrat b("Julien Chièze", 150);

    Form f("OPE SPE", 5, 1);

    try
    {
        b.signForm(&f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.signForm(&f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << f;

    return 0;
}
