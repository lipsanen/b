#include "ob_plugin/plugin.h"
#include "bcommon/plugin.h"

static bcommon::Plugin plugin;
void* g_pOBPlugin = (void*)&plugin;

int getOBVersionCode()
{
    return bcommon::getVersionCode();
}
