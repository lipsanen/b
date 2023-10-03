#include "bcommon/feature.h"
#include <cstdio>

// A dummy feature to test conditional compilation based on the SDK version
int bcommon::getVersionCode()
{
#ifdef STEAMPIPE
    return 0;
#else
    return 1;
#endif
}
