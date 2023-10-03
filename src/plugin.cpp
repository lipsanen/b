#include "ob_plugin/plugin.h"
#include "steampipe_plugin/plugin.h"
#include "bcommon/feature.h"
#include <cstring>

extern "C" void* CreateInterface(const char *pName, int *pReturnCode) {
    if(pReturnCode) {
        *pReturnCode = 1; // not sure if 0 is success or failure but it appears this is not checked anyway
    }

    if(strcmp(pName, "ISERVERPLUGINCALLBACKS003") == 0) {
        return g_pSteampipePlugin;
    } else {
        return g_pOBPlugin;
    }

}
