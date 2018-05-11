#pragma once
#include "../interfaces/serializable.hxx"

namespace CE::Utils
{
    class Serializable : public Interfaces::ISerializable
    {
    public:
        Core::Status ToString(std::string &output);
        Core::Status FromString(const std::string &input);

        Core::Status ToFile(const std::string &filename);
        Core::Status FromFile(const std::string &filename);
    };
}