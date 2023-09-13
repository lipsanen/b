#include "ob_plugin/plugin.h"
#include "engine/iserverplugin.h"
#include "bob/interface.hpp"

class OBPlugin : public IServerPluginCallbacks
{
    virtual bool Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)  override;
    virtual void Unload( void ) override;
    virtual void Pause( void ) override;
    virtual void UnPause( void ) override;
    virtual const char *GetPluginDescription( void ) override;
    virtual void LevelInit( char const *pMapName ) override;
    virtual void ServerActivate( edict_t *pEdictList, int edictCount, int clientMax ) override;
    virtual void GameFrame( bool simulating ) override;
    virtual void LevelShutdown( void ) override;
    virtual void ClientActive( edict_t *pEntity ) override;
    virtual void ClientDisconnect( edict_t *pEntity ) override;
    virtual void ClientPutInServer( edict_t *pEntity, char const *playername ) override;
    virtual void SetCommandClient( int index ) override;
    virtual void ClientSettingsChanged( edict_t *pEdict ) override;
    virtual PLUGIN_RESULT ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen ) override;
    virtual PLUGIN_RESULT ClientCommand( edict_t *pEntity, const CCommand &args ) override;
    virtual PLUGIN_RESULT NetworkIDValidated( const char *pszUserName, const char *pszNetworkID ) override;
    virtual void OnQueryCvarValueFinished( QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue ) override;
};

static OBPlugin plugin;
void* g_pOBPlugin = (void*)&plugin;

bool OBPlugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    ConnectInterfaces(interfaceFactory, gameServerFactory);
    return true;
}

void OBPlugin::Unload( void ){}

const char *OBPlugin::GetPluginDescription( void )
{
    return "B - orangebox plugin";
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
