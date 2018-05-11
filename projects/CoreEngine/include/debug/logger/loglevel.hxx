#pragma once
#include <cstdint>

namespace CE::Debug::Logger
{
    enum class LogLevel : std::uint8_t
    {
        Trace = 0x20,
        Debug = 0x40,
        Info = 0x60,
        Warning = 0x80,
        Error = 0xA0,
        Fatal = 0xC0,
    };

    static inline std::string LogLevelToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::Trace:
            return "&T";
        case LogLevel::Debug:
            return "&D";
        case LogLevel::Info:
            return "&I";
        case LogLevel::Warning:
            return "&W";
        case LogLevel::Error:
            return "&E";
        case LogLevel::Fatal:
            return "&F";
        default:
            return "&U";
        }
    }
}