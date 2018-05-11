#pragma once
#include <cstdint>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>

namespace CE::Core
{
    enum class StatusCode : std::uint16_t
    {
        Success = 0x0000,

        Unknown = 0x0001,
        NotImplemented,
        Unsupported,
        InvalidArgument,

        NotReady,
        NotFound,
        OutOfResources,
        BufferTooSmall,

        FailedToOpen,
        FailedToClose,
        FailedToRead,
        FailedToWrite,
    };

    inline static std::string StatusCodeToString(StatusCode code)
    {
        std::stringstream stream;

        switch (code)
        {
        case CE::Core::StatusCode::Success:
            stream << "StatusCode::Success";
            break;
        case CE::Core::StatusCode::Unknown:
            stream << "StatusCode::Unknown";
            break;
        case CE::Core::StatusCode::NotImplemented:
            stream << "StatusCode::NotImplemented";
            break;
        case CE::Core::StatusCode::Unsupported:
            stream << "StatusCode::Unsupported";
            break;
        case CE::Core::StatusCode::InvalidArgument:
            stream << "StatusCode::InvalidArgument";
            break;
        case CE::Core::StatusCode::NotReady:
            stream << "StatusCode::NotReady";
            break;
        case CE::Core::StatusCode::NotFound:
            stream << "StatusCode::NotFound";
            break;
        case CE::Core::StatusCode::OutOfResources:
            stream << "StatusCode::OutOfResources";
            break;
        case CE::Core::StatusCode::BufferTooSmall:
            stream << "StatusCode::BufferTooSmall";
            break;
        case CE::Core::StatusCode::FailedToOpen:
            stream << "StatusCode::FailedToOpen";
            break;
        case CE::Core::StatusCode::FailedToClose:
            stream << "StatusCode::FailedToClose";
            break;
        case CE::Core::StatusCode::FailedToRead:
            stream << "StatusCode::FailedToRead";
            break;
        case CE::Core::StatusCode::FailedToWrite:
            stream << "StatusCode::FailedToWrite";
            break;
        default:
            stream << "StatusCode::<unknown>";
            break;
        }

        stream << " (0x";
        stream << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(code);
        stream << ")";
        return stream.str();
    }
}