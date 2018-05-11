#pragma once
#include <functional>
#include <ostream>
#include <vector>

namespace CE::Debug::Logger
{
    using LogChain = std::vector<std::reference_wrapper<std::ostream>>;
}