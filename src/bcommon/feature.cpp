#include "bcommon/feature.h"
#include "interface.hpp"
#include <cstdio>

// A dummy feature to test conditional compilation based on the SDK version
int bcommon::getVersionCode()
{
    return sdk_version();
}
