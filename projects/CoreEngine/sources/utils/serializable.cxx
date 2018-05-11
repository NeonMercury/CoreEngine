#include <CoreEngine.hxx>

#include <fstream>
#include <sstream>

namespace CE::Utils
{
    Core::Status Serializable::ToString(std::string &output)
    {
        CE_LTRACE(output);

        std::stringstream stream;
        CE_CHECK_STATUS(ToStream(stream));
        output = stream.str();
        return Core::StatusCode::Success;
    }

    Core::Status Serializable::FromString(const std::string &input)
    {
        CE_LTRACE(input);

        std::istringstream stream(input);
        return FromStream(stream);
    }

    Core::Status Serializable::ToFile(const std::string &filename)
    {
        CE_LTRACE(filename);

        std::ofstream file(filename, std::ios::out | std::ios::binary);
        if (!file)
        {
            return Core::StatusCode::FailedToOpen;
        }

        return ToStream(file);
    }

    Core::Status Serializable::FromFile(const std::string &filename)
    {
        CE_LTRACE(filename);

        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (!file)
        {
            return Core::StatusCode::FailedToOpen;
        }

        return FromStream(file);
    }
}