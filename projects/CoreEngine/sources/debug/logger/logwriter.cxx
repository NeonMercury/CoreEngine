#include <CoreEngine.hxx>

namespace CE::Debug::Logger
{
    LogWriter::LogWriter(LogChain &chain, const std::string &filename, 
        const size_t line, const std::string &function, LogLevel level, bool writelog) :
        chain(chain),
        writelog(writelog)
    {
        write([&](std::ostream &stream)
        {
            static const std::string offset = "            ";
            auto timepoint = std::chrono::system_clock::now();
            auto timestamp = std::chrono::system_clock::to_time_t(timepoint);
            auto millisecs = timepoint.time_since_epoch().count() % 1000;
            
            stream << LogLevelToString(level);
            stream << "[" << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %X");
            stream << "." << std::setw(3) << std::setfill('0') << millisecs << "] ";
            stream << filename << ":" << std::setw(4) << std::setfill('0') << line;
            stream << " -> " << function << ":\n>>" << offset;
        });
    }

    LogWriter::~LogWriter()
    {
        write([](std::ostream &stream)
        {
            stream << std::endl << std::endl;
        });
    }

    void LogWriter::write(const std::function<void(std::ostream &)> &handler)
    {
        if (!writelog || !handler)
        {
            return;
        }

        for (auto &stream : chain)
        {
            handler(stream);
        }
    }
}