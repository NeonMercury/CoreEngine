#include <CoreEngine.hxx>

std::ostream &operator<<(std::ostream &stream, CE::Core::StatusCode code)
{
    stream << CE::Core::StatusCodeToString(code);
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const CE::Core::Status &status)
{
    stream << static_cast<CE::Core::StatusCode>(status);
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const CE::Core::Version &version)
{
    stream << "Core::Version(\"";
    stream << version.GetMajor() << "." <<
        version.GetMinor() << "." <<
        version.GetPatch();

    if (version.GetBuild() > 0) stream << "." << version.GetBuild();
    if (version.GetPrefix().length() > 0) stream << "-" << version.GetPrefix();
    if (version.GetMetaData().length() > 0) stream << "+" << version.GetMetaData();
    if (version.GetCodename().length() > 0) stream << " " << version.GetCodename();
    stream << "\")";

    return stream;
}