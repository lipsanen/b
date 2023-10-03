#include "steampipe_plugin/plugin.h"
#include "bipe/engine/iserverplugin.h"
#include "bipe/interface.hpp"
#include "bcommon/feature.h"

class SteampipePlugin : public IServerPluginCallbacks
{
    virtual bool Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)  override;
    virtual void Unload( void ) override;
    virtual void Pause( void ) override {}
    virtual void UnPause( void ) override {}
    virtual const char *GetPluginDescription( void ) override;
    virtual void LevelInit( char const *pMapName ) override {}
    virtual void ServerActivate( edict_t *pEdictList, int edictCount, int clientMax ) override {}
    virtual void GameFrame( bool simulating ) override {}
    virtual void LevelShutdown( void ) override {}
    virtual void ClientActive( edict_t *pEntity ) override {}
    virtual void ClientDisconnect( edict_t *pEntity ) override {}
    virtual void ClientPutInServer( edict_t *pEntity, char const *playername ) override {}
    virtual void SetCommandClient( int index ) override {}
    virtual void ClientSettingsChanged( edict_t *pEdict ) override {}
    virtual PLUGIN_RESULT ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen ) override;
    virtual PLUGIN_RESULT ClientCommand( edict_t *pEntity, const CCommand &args ) override;
    virtual PLUGIN_RESULT NetworkIDValidated( const char *pszUserName, const char *pszNetworkID ) override;
    virtual void OnQueryCvarValueFinished( QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue ) override {}
    virtual void OnEdictAllocated( edict_t *edict ) override {}
    virtual void OnEdictFreed(const edict_t *edict ) override {}	
};

static SteampipePlugin plugin;
void* g_pSteampipePlugin = (void*)&plugin;

bool SteampipePlugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    ConnectInterfaces(interfaceFactory, gameServerFactory);
    return true;
}

void SteampipePlugin::Unload( void ){}

const char *SteampipePlugin::GetPluginDescription( void )
{
    return "B - steampipe plugin";
}

PLUGIN_RESULT SteampipePlugin::ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT SteampipePlugin::ClientCommand( edict_t *pEntity, const CCommand &args )
{
    return PLUGIN_CONTINUE;
}

PLUGIN_RESULT SteampipePlugin::NetworkIDValidated( const char *pszUserName, const char *pszNetworkID )
{
    return PLUGIN_CONTINUE;
}

int getSteampipeVersionCode()
{
    return bcommon::getVersionCode();
}
