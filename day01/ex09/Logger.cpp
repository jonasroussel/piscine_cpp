/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:58:53 by jroussel          #+#    #+#             */
/*   Updated: 2019/10/15 13:28:04 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

static std::string  now( void )
{
    time_t _time = time(&_time);
	struct tm *date = localtime(&_time);

    int year = 1900 + date->tm_year;
    int mon = date->tm_mon + 1;
    int day = date->tm_mday;
    
    int hour = date->tm_hour;
    int min = date->tm_min;
    int sec = date->tm_sec;

    std::stringstream   ss;
    
    ss << "["
    << year
    << "/"
    << (mon < 10 ? "0" : "") << mon
    << "/"
    << (day < 10 ? "0" : "") << day
    << " "
    << (hour < 10 ? "0" : "") << hour
    << ":"
    << (min < 10 ? "0" : "") << min
    << ":"
    << (sec < 10 ? "0" : "") << sec
    << "]";

    return ss.str();
}

void        Logger::logToConsole( std::string const & msg )
{
    std::cout << makeLogEntry(msg) << std::endl;
}

void        Logger::logToFile( std::string const & msg )
{
    std::ofstream   os;
    os.open(this->file, std::ofstream::out | std::ofstream::app);

    if (os.fail())
    {
        std::cout << "error: " << strerror(errno) << std::endl;
        return;
    }

    os << makeLogEntry(msg) << std::endl;

    os.close();
}

std::string Logger::makeLogEntry( std::string const & msg )
{
    std::stringstream   ss;

    ss << now() << " " << msg;

    return ss.str();   
}

Logger::Logger( std::string _file ) : file(_file)
{
    logsFunctions["console"] = &Logger::logToConsole;
    logsFunctions["file"] = &Logger::logToFile;
}

Logger::~Logger( void ) {}

void    Logger::log( std::string const & dest, std::string const & msg )
{
    if (this->logsFunctions.find(dest) != this->logsFunctions.end())
    {
        (this->*logsFunctions[dest])( msg );
    }
}
