#include "bcommon/plugin.h"
#include "interface.hpp"

bool bcommon::Plugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    ConnectInterfaces(interfaceFactory, gameServerFactory);
    return true;
}

void bcommon::Plugin::Unload( void ){}

const char *bcommon::Plugin::GetPluginDescription( void )
{
    return "B";
}

PLUGIN_RESULT bcommon::Plugin::ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT bcommon::Plugin::ClientCommand( edict_t *pEntity, const CCommand &args )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT bcommon::Plugin::NetworkIDValidated( const char *pszUserName, const char *pszNetworkID )
{
    return PLUGIN_CONTINUE;
}
