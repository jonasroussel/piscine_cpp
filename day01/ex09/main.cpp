/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:57:37 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 13:31:04 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main( void )
{
    Logger  logger("./logger.log");

    logger.log("console", "This is a test");
    logger.log("file", "This is another test wrote in a file this time");
    logger.log("file", "And another, to test if append works !");

    return 0;
}
