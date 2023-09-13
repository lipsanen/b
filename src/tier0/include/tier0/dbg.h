#pragma once

#include <cassert>

namespace tier0
{
    typedef void(*PrintFunc)(const char* msg, ...);

    #define Assert(x) assert(x)
    extern PrintFunc AssertMsg;
    extern PrintFunc ConMsg;
    extern PrintFunc Msg;
    extern PrintFunc Warning;
    extern PrintFunc DevMsg;
    extern PrintFunc DevWarning;
    inline void VerifyEquals(...) { }
}

using namespace tier0;
