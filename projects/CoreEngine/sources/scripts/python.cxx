#include <CoreEngine.hxx>

namespace CE::Scripts
{
    Python::Python()
    {
        Py_Initialize();
    }

    Python::~Python()
    {
        Py_FinalizeEx();
    }

    Core::Status Python::Execute(const std::string &code)
    {
        PyRun_SimpleString(code.c_str());
        return Core::StatusCode::Success;
    }
}