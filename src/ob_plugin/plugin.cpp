#include "ob_plugin/ob_plugin.h"
#include "bob/interface.hpp"

OBPlugin bob::g_OBPlugin;

bool OBPlugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    ConnectInterfaces(interfaceFactory, gameServerFactory);
    return true;
}

void OBPlugin::Unload( void ){}

const char *OBPlugin::GetPluginDescription( void )
{
    return "B";
}

PLUGIN_RESULT OBPlugin::ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT OBPlugin::ClientCommand( edict_t *pEntity, const CCommand &args )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT OBPlugin::NetworkIDValidated( const char *pszUserName, const char *pszNetworkID )
{
    return PLUGIN_CONTINUE;
}

void OBPlugin::Pause( void ){}
void OBPlugin::UnPause( void ){}
void OBPlugin::LevelInit( char const *pMapName ){}
void OBPlugin::ServerActivate( edict_t *pEdictList, int edictCount, int clientMax ){}
void OBPlugin::GameFrame( bool simulating ){}
void OBPlugin::LevelShutdown( void ){}
void OBPlugin::ClientActive( edict_t *pEntity ){}
void OBPlugin::ClientDisconnect( edict_t *pEntity ){}
void OBPlugin::ClientPutInServer( edict_t *pEntity, char const *playername ){}
void OBPlugin::SetCommandClient( int index ){}
void OBPlugin::ClientSettingsChanged( edict_t *pEdict ){}
void OBPlugin::OnQueryCvarValueFinished( QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue ){}
