#include <Log.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace gamePlay
{

Log::Log(const std::string& name) : _name(name)
{

}

void Log::logMessage(const std::string& msg, Level l)
{
    boost::posix_time::ptime _currTime = boost::posix_time::second_clock::local_time();
    std::cout << boost::posix_time::to_simple_string(_currTime) <<
            " :: " << _name << " - " << msg << std::endl;
}



}
