#include <CoreEngine.hxx>

int main(int argc, char **argv)
{
    std::vector<std::string> args(argv, argv + argc);
    std::unique_ptr<CE::CoreEngine> engine = std::make_unique<CE::CoreEngine>(args);
    return engine->Run();
}