/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:57:59 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 13:21:54 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <ctime>

class Logger
{
private:
    typedef void (Logger::*LogFunction)( std::string const & );
    
    std::string                                         file;
    std::map<std::string const, Logger::LogFunction>    logsFunctions;

    void        logToConsole( std::string const & msg );
    void        logToFile( std::string const & msg );
    std::string makeLogEntry( std::string const & msg );

public:
    Logger( std::string file );
    ~Logger( void );

    void    log( std::string const & dest, std::string const & msg );
};

#endif
