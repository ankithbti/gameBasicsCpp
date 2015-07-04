/* 
 * File:   Log.hpp
 * Author: ankithbti
 *
 * Created on 4 July, 2015, 3:33 PM
 */

#ifndef LOG_HPP
#define	LOG_HPP

#include <iostream>


namespace gamePlay
{

class Log
{
public:

    enum Level
    {
        ERROR,
        WARNING,
        INFO,
        DEBUG
    };

private:
    std::string _name;


public:
    Log(const std::string& name);
    void logMessage(const std::string& msg, Level l = DEBUG);

};

}


#endif	/* LOG_HPP */

