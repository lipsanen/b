#include "steampipe_plugin/plugin.h"
#include "bcommon/plugin.h"

static bcommon::Plugin plugin;
void* g_pSteampipePlugin = (void*)&plugin;

int getSteampipeVersionCode()
{
    return bcommon::getVersionCode();
}
