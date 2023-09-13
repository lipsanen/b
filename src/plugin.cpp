#include "ob_plugin/ob_plugin.h"

extern "C" void* CreateInterface(const char *pName, int *pReturnCode) {
    if(pReturnCode) {
        *pReturnCode = 1; // not sure if 0 is success or failure but it appears this is not checked anyway
    }
    return &g_OBPlugin;
}
