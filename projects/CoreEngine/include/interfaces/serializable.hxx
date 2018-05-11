#pragma once
#include <istream>
#include <ostream>

#include "../core/status.hxx"

namespace CE::Interfaces
{
    struct ISerializable
    {
        virtual ~ISerializable() {}

        virtual Core::Status ToStream(std::ostream &stream) = 0;
        virtual Core::Status FromStream(std::istream &stream) = 0;
    };
}