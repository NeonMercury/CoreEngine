#pragma once
#include <Python.h>

namespace CE::Scripts
{
    class Python
    {
    public:
        Python();
        virtual ~Python();

        Python(const Python &interpreter) = default;
        Python &operator=(const Python &interpreter) = default;

        Python(Python &&interpreter) = default;
        Python &operator=(Python &&interpreter) = default;

        Core::Status Execute(const std::string &code);
    };
}
