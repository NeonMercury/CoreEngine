#pragma once
#include <cstdint>

namespace CE::Utils
{
    enum class Comparable : std::int8_t
    {
        Less = -1, 
        Equal = 0, 
        Greater = 1,
    };
}
