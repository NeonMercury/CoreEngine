#include <CoreEngine.hxx>

namespace CE::Core
{
    Version::Version(const std::string &version) : Version()
    {
        static const std::regex parse_re = std::regex("(\\d+)\\.(\\d+)\\.(\\d+)(\\.(\\d+))?(-([0-9A-Za-z-.]+))?(\\+([0-9A-Za-z-.]+))?(\\s*(.*))?");
        std::smatch matches;
        if (std::regex_search(version, matches, parse_re))
        {
            size_t i = 1;
            while (i < matches.size())
            {
                std::string match = matches[i];
                if (i == 1) major = std::stoi(match);
                else if (i == 2) minor = std::stoi(match);
                else if (i == 3) patch = std::stoi(match);
                else if (match.length() > 0)
                {
                    if (match[0] == '.')
                    {
                        match = matches[++i];
                        build = std::stoi(match);
                    }
                    else if (match[0] == '-')
                    {
                        prefix = matches[++i];
                    }
                    else if (match[0] == '+')
                    {
                        metadata = matches[++i];
                    }
                    else if (codename.length() == 0)
                    {
                        codename = matches[++i];
                    }
                }
                i++;
            }
        }
    }

    bool Version::operator<(const Version &version) const
    {
        if (major < version.major) return true;
        if (major > version.major) return false;

        if (minor < version.minor) return true;
        if (minor > version.minor) return false;

        if (patch < version.patch) return true;
        if (patch > version.patch) return false;

        if (prefix.length() > 0 && version.prefix.length() == 0)
        {
            return true;
        }

        return false;
    }
}