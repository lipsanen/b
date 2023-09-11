#include "tier1/convar.h"
#include "engine/iserverplugin.h"

ConVar test("test", "0");

class OSPlugin : public IServerPluginCallbacks {
    // Initialize the plugin to run
    // Return false if there is an error during startup.
    virtual bool Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)  override {
        return true;
    }

    // Called when the plugin should be shutdown
    virtual void Unload( void ) override {

    }

    // called when a plugins execution is stopped but the plugin is not unloaded
    virtual void Pause( void ) override {
        
    }

    // called when a plugin should start executing again (sometime after a Pause() call)
    virtual void UnPause( void ) override {
        
    }

    // Returns string describing current plugin.  e.g., Admin-Mod.  
    virtual const char *GetPluginDescription( void ) override {
        return "OSPlugin";
    }      

    // Called any time a new level is started (after GameInit() also on level transitions within a game)
    virtual void LevelInit( char const *pMapName ) override {
        
    }

    // The server is about to activate
    virtual void ServerActivate( edict_t *pEdictList, int edictCount, int clientMax ) override {
        
    }

    // The server should run physics/think on all edicts
    virtual void GameFrame( bool simulating ) override {
        
    }

    // Called when a level is shutdown (including changing levels)
    virtual void LevelShutdown( void ) override {
        
    }

    // Client is going active
    virtual void ClientActive( edict_t *pEntity ) override {
        
    }
    
    // Client is disconnecting from server
    virtual void ClientDisconnect( edict_t *pEntity ) override {
        
    }
    
    // Client is connected and should be put in the game
    virtual void ClientPutInServer( edict_t *pEntity, char const *playername ) override {
        
    }

    // Sets the client index for the client who typed the command into their console
    virtual void SetCommandClient( int index ) override {
        
    }

    // A player changed one/several replicated cvars (name etc)
    virtual void ClientSettingsChanged( edict_t *pEdict ) override {
        
    }

    // Client is connecting to server ( set retVal to false to reject the connection )
    //	You can specify a rejection message by writing it into reject
    virtual PLUGIN_RESULT ClientConnect( bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen ) override {
        return PLUGIN_CONTINUE;
    }

    // The client has typed a command at the console
    virtual PLUGIN_RESULT ClientCommand( edict_t *pEntity, const CCommand &args ) override {
        return PLUGIN_CONTINUE;
    }

    // A user has had their network id setup and validated 
    virtual PLUGIN_RESULT NetworkIDValidated( const char *pszUserName, const char *pszNetworkID ) override {
        return PLUGIN_CONTINUE;
    }

    // This is called when a query from IServerPluginHelpers::StartQueryCvarValue is finished.
    // iCookie is the value returned by IServerPluginHelpers::StartQueryCvarValue.
    // Added with version 2 of the interface.
    virtual void OnQueryCvarValueFinished( QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue ) override {
        
    }

    // added with version 3 of the interface.
    virtual void OnEdictAllocated( edict_t *edict ) override {
        
    }

    virtual void OnEdictFreed( const edict_t *edict  ) override {
        
    }	
};


static OSPlugin plugin;

extern "C" void* CreateInterface(const char *pName, int *pReturnCode) {
    if(pReturnCode) {
        *pReturnCode = 1; // not sure if 0 is success or failure but it appears this is not checked anyway
    }
    return &plugin;
}
