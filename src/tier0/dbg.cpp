#include "tier0/dbg.h"
#include <cstdio>

PrintFunc tier0::AssertMsg = printf;
PrintFunc tier0::ConMsg = printf;
PrintFunc tier0::Msg = printf;
PrintFunc tier0::Warning = printf;
PrintFunc tier0::DevMsg = printf;
PrintFunc tier0::DevWarning = printf;
