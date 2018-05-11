#pragma once
#include <functional>
#include <ostream>
#include <string>
#include <vector>

#include "logchain.hxx"
#include "loglevel.hxx"
#include "logwriter.hxx"

#include "../../core/predef.hxx"
#include "../../core/status.hxx"

#include "../../utils/numargs.hxx"

#define CE_LOG_WRITE(log, level) log.Write(CE_SHORT_FILE, __LINE__, CE_FUNCTION_NAME, level)

#define CE_LVAL(var) "[" << #var << "=" << var << "] "
#define CE_LVALS(...) FOREACH(CE_LVAL, __VA_ARGS__)

#define CE_LTRACE_(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Trace)
#define CE_LTRACE_EX(log, ...) CE_LTRACE_(log) << CE_LVALS(__VA_ARGS__);

#define CE_LDEBUG_EX(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Debug)
#define CE_LINFO_EX(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Info)
#define CE_LWARNING_EX(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Warning)
#define CE_LERROR_EX(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Error)
#define CE_LFATAL_EX(log) CE_LOG_WRITE(log, CE::Debug::Logger::LogLevel::Fatal)

#define CE_LTRACE(...) CE_LTRACE_EX(CE::Debug::Logger::Log::GetDefaultLogger(), __VA_ARGS__)
#define CE_LTRACE_EMPTY CE_LOG_WRITE(CE::Debug::Logger::Log::GetDefaultLogger(), CE::Debug::Logger::LogLevel::Trace)
#define CE_LDEBUG CE_LDEBUG_EX(CE::Debug::Logger::Log::GetDefaultLogger())
#define CE_LINFO CE_LINFO_EX(CE::Debug::Logger::Log::GetDefaultLogger())
#define CE_LWARNING CE_LWARNING_EX(CE::Debug::Logger::Log::GetDefaultLogger())
#define CE_LERROR CE_LERROR_EX(CE::Debug::Logger::Log::GetDefaultLogger())
#define CE_LFATAL CE_LFATAL_EX(CE::Debug::Logger::Log::GetDefaultLogger())

namespace CE::Debug::Logger
{
    class Log
    {
    public:
        Log(LogChain chain = {}, LogLevel minlevel = LogLevel::Trace);
        ~Log();

        Log(const Log &log) = default;
        Log &operator=(const Log &log) = default;

        Log(Log &&log) = default;
        Log &operator=(Log &&log) = default;

        inline void AddToChain(std::ostream &stream)
        {
            chain.push_back(stream);
        }

        LogWriter Write(const std::string &filename, const size_t line,
            const std::string &function, LogLevel level);

        inline void SetLogLevel(LogLevel level) 
        { 
            minlevel = level; 
        }

        inline LogLevel GetLogLevel() const 
        { 
            return minlevel; 
        }

        inline static void SetDefaultLogger(const Log &logger)
        {
            default_logger = logger;
        }

        inline static Log &GetDefaultLogger()
        {
            return default_logger;
        }

    private:
        static Log default_logger;

        LogChain chain;
        LogLevel minlevel;
    };    
}