#pragma once
#include <cstdint>
#include <regex>
#include <string>

namespace CE::Core
{
    class Version
    {
    public:
        Version(const std::uint16_t major = 0,
            const std::uint16_t minor = 0,
            const std::uint16_t patch = 0,
            const std::uint16_t build = 0,
            const std::string &prefix = "",
            const std::string &metadata = "",
            const std::string &codename = "") :
            major(major),
            minor(minor),
            patch(patch),
            build(build),
            prefix(prefix),
            metadata(metadata),
            codename(codename)
        { }
        Version(const std::string &version);
        ~Version() = default;

        Version(const Version &version) = default;
        Version &operator=(const Version &version) = default;

        Version(Version &&version) = default;
        Version &operator=(Version &&version) = default;

        inline void SetMajor(const std::uint16_t value) { major = value; }
        inline void SetMinor(const std::uint16_t value) { minor = value; }
        inline void SetPatch(const std::uint16_t value) { patch = value; }
        inline void SetBuild(const std::uint16_t value) { build = value; }
        inline void SetPrefix(const std::string &value) { prefix = value; }
        inline void SetMetaData(const std::string &value) { metadata = value; }
        inline void SetCodename(const std::string &value) { codename = value; }

        inline std::uint16_t GetMajor() const { return major; }
        inline std::uint16_t GetMinor() const { return minor; }
        inline std::uint16_t GetPatch() const { return patch; }
        inline std::uint16_t GetBuild() const { return build; }
        inline const std::string &GetPrefix() const { return prefix; }
        inline const std::string &GetMetaData() const { return metadata; }
        inline const std::string &GetCodename() const { return codename; }

        bool operator<(const Version &version) const;
        
        inline bool operator==(const Version &version) const { return !(*this < version) && !(version < *this); }
        inline bool operator!=(const Version &version) const { return !(*this == version); }
        inline bool operator<=(const Version &version) const { return *this < version || *this == version; }
        inline bool operator>(const Version &version) const { return !(*this <= version); }
        inline bool operator>=(const Version &version) const { return !(*this < version); }

    private:
        std::uint16_t major;
        std::uint16_t minor;
        std::uint16_t patch;
        std::uint16_t build;

        std::string prefix;
        std::string metadata;

        std::string codename;
    };
}