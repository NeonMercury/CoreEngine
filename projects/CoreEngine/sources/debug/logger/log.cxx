#include <CoreEngine.hxx>

namespace CE::Debug::Logger
{
    Log Log::default_logger;

    Log::Log(LogChain chain, LogLevel minlevel) :
        chain(chain),
        minlevel(minlevel)
    {

    }

    Log::~Log()
    {

    }

    LogWriter Log::Write(const std::string &filename, const size_t line, 
        const std::string &function, LogLevel level)
    {
        return LogWriter(chain, filename, line, function, level, level >= minlevel);
    }    
}