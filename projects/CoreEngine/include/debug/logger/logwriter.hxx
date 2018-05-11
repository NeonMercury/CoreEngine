#pragma once
#include <chrono>
#include <type_traits>
#include <functional>
#include <iomanip>

#include "logchain.hxx"

#include "../../core/platform.hxx"

namespace CE::Debug::Logger
{
    class LogWriter
    {
    public:
        LogWriter(LogChain &chain, const std::string &filename, 
            const size_t line, const std::string &function, LogLevel level, bool writelog = true);
        ~LogWriter();

        template <class T>
        LogWriter &operator<<(T data)
        {
            write([&data](std::ostream &stream)
            {
                stream << data;
            });
            return *this;
        }

    private:
        void write(const std::function<void(std::ostream &)> &handler);

    private:
        LogChain &chain;
        bool writelog = true;
    };
}