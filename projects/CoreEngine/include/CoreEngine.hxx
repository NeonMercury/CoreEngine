#pragma once
#include "core/core.hxx"
#include "debug/debug.hxx"
#include "interfaces/interfaces.hxx"
#include "utils/utils.hxx"

#include <fstream>
#include <memory>

namespace CE
{
    class CoreEngine
    {
    public:
        CoreEngine(const std::vector<std::string> &args);
        ~CoreEngine();

        CoreEngine(const CoreEngine &engine) = delete;
        CoreEngine &operator=(const CoreEngine &engine) = delete;

        CoreEngine(CoreEngine &&engine) = delete;
        CoreEngine &operator=(CoreEngine &&engine) = delete;

        Core::Status Run();

    private:
        void initializeLogger();

    private:
        static const Core::Version version;

        std::ofstream log_file;
        Debug::Logger::Log logger;
    };
}