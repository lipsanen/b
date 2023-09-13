#pragma once

namespace tier0
{
    typedef int(*PrintFunc)(const char* msg, ...);

    extern PrintFunc AssertMsg;
    extern PrintFunc ConMsg;
    extern PrintFunc Msg;
    extern PrintFunc Warning;
    extern PrintFunc DevMsg;
    extern PrintFunc DevWarning;
    inline void VerifyEquals(...) { }
}

using namespace tier0;
