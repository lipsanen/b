#include "tier0/dbg.h"
#include <cstdio>
#include <cstdarg>

static void printf_wrapper(const char* msg, ...)
{
    va_list a_list;
    va_start(a_list, msg);
    vprintf(msg, a_list);
    va_end(a_list);
}

PrintFunc tier0::AssertMsg = printf_wrapper;
PrintFunc tier0::ConMsg = printf_wrapper;
PrintFunc tier0::Msg = printf_wrapper;
PrintFunc tier0::Warning = printf_wrapper;
PrintFunc tier0::DevMsg = printf_wrapper;
PrintFunc tier0::DevWarning = printf_wrapper;
