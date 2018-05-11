#pragma once

#if defined(_MSC_VER)
#   define CE_FUNCTION_NAME __FUNCSIG__
#elif defined(__GCC__)
#   define CE_FUNCTION_NAME __PRETTY_FUNCTION__ 
#else
#   define CE_FUNCTION_NAME __FUNCTION__
#endif

namespace CE::Core
{
    using cstr = const char * const;

    static constexpr cstr past_last_slash(cstr str, cstr last_slash)
    {
        if (*str == '\0')
        {
            return last_slash;
        }
        
        if (*str == '/' || *str == '\\')
        {
            return past_last_slash(str + 1, str + 1);
        }

        return past_last_slash(str + 1, last_slash);
    }

    static constexpr cstr past_last_slash(cstr str)
    {
        return past_last_slash(str, str);
    }
}

#define CE_SHORT_FILE CE::Core::past_last_slash(__FILE__)