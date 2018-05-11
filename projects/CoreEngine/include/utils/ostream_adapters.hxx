#pragma once
#include <algorithm>
#include <map>
#include <vector>

#include "../core/config.hxx"
#include "../core/status.hxx"
#include "../core/version.hxx"

std::ostream &operator<<(std::ostream &stream, CE::Core::StatusCode code);

std::ostream &operator<<(std::ostream &stream, const CE::Core::Status &status);

std::ostream &operator<<(std::ostream &stream, const CE::Core::Version &version);

template <class T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &vec)
{
    namespace Config = CE::Core::Config::Utils;

    size_t show_count = vec.size();
    if (Config::MaxElementsToShow > 0 and show_count > Config::MaxElementsToShow)
    {
        show_count = Config::MaxElementsToShow;
    }

    stream << "std::vector( /* size == " << vec.size() << " */ {";
    for (size_t i = 0; i < show_count; i++)
    {
        stream << vec[i];
        if (i + 1 < vec.size())
        {
            stream << ", ";
        }
    }
    if (vec.size() > show_count)
    {
        stream << "...";
    }
    stream << "})";

    return stream;
}

template <class T, class U>
std::ostream &operator<<(std::ostream &stream, const std::map<T, U> &dict)
{
    namespace Config = CE::Core::Config::Utils;

    size_t show_count = dict.size();
    if (Config::MaxElementsToShow > 0 and show_count > Config::MaxElementsToShow)
    {
        show_count = Config::MaxElementsToShow;
    }

    std::vector<std::pair<T, U>> values(show_count);

    std::partial_sort_copy(dict.begin(), dict.end(), values.begin(), values.end(),
        [](const std::pair<T, U> &a, const std::pair<T, U> &b)
        {
            return a.first < b.first;
        });

    stream << "std::map( /* size == " << dict.size() << " */ {";
    for (size_t i = 0; i < show_count; i++)
    {
        stream << "{" << values[i].first << ": " << values[i].second << "}";
        if (i + 1 < values.size())
        {
            stream << ", ";
        }
    }
    if (dict.size() > show_count)
    {
        stream << "...";
    }
    stream << "})";

    return stream;
}