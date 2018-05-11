#include <CoreEngine.hxx>

namespace CE
{
    const Core::Version CoreEngine::version("0.1.0-prealpha Moscow");

    CoreEngine::CoreEngine(const std::vector<std::string> &args)
    {
        initializeLogger();

        CE_LINFO << "CoreEngine started. Version: " << version;
        CE_LTRACE(args);
    }

    CoreEngine::~CoreEngine()
    {
        CE_LTRACE_EMPTY;

        CE_LINFO << "CoreEngine finished.";
    }

    CE::Core::Status CoreEngine::Run()
    {
        CE_LTRACE_EMPTY;



        return CE::Core::StatusCode::Success;
    }

    void CoreEngine::initializeLogger()
    {
        logger.AddToChain(log_file);
        Debug::Logger::Log::SetDefaultLogger(logger);

        log_file.open("cengine.log", std::ios::out);
    }
}