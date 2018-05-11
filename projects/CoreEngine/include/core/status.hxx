#pragma once
#include "statuscode.hxx"

#define CE_CHECK_STATUS(st) { auto ce_status = st; if (ce_status.IsFailed()) return ce_status; }

namespace CE::Core
{
    class Status
    {
    public:
        Status(const StatusCode &code = StatusCode::Success);
        ~Status() = default;

        Status(const Status &status) = default;
        Status &operator=(const Status &status) = default;

        Status(Status &&status) = default;
        Status &operator=(Status &&status) = default;

        inline bool IsFailed() const
        {
            return code != StatusCode::Success;
        }

        inline bool IsSucceeded() const
        {
            return !IsFailed();
        }

        inline operator StatusCode() const
        {
            return code;
        }

        inline operator int() const
        {
            return static_cast<int>(code);
        }

    private:
        StatusCode code;
    };
}