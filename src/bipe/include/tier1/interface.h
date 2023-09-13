#pragma once

#ifdef _LINUX
#include <dlfcn.h> // dlopen,dlclose, et al
#include <unistd.h>

#define HMODULE void *
#define GetProcAddress dlsym

#define _snprintf snprintf
#endif

// TODO: move interface.cpp into tier0 library.
#include "tier0/platform.h"

namespace bipe
{
    // All interfaces derive from this.
    class IBaseInterface
    {
    public:
        virtual	~IBaseInterface() {}
    };

    #if !defined( _X360 )
    #define CREATEINTERFACE_PROCNAME	"CreateInterface"
    #else
    // x360 only allows ordinal exports, .def files export "CreateInterface" at 1
    #define CREATEINTERFACE_PROCNAME	((const char*)1)
    #endif

    typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);
    typedef void* (*InstantiateInterfaceFn)();

    // Used internally to register classes.
    class InterfaceReg
    {
    public:
        InterfaceReg(InstantiateInterfaceFn fn, const char *pName);

    public:
        InstantiateInterfaceFn	m_CreateFn;
        const char				*m_pName;

        InterfaceReg			*m_pNext; // For the global list.
        static InterfaceReg		*s_pInterfaceRegs;
    };

    // Use this to expose an interface that can have multiple instances.
    // e.g.:
    // EXPOSE_INTERFACE( CInterfaceImp, IInterface, "MyInterface001" )
    // This will expose a class called CInterfaceImp that implements IInterface (a pure class)
    // clients can receive a pointer to this class by calling CreateInterface( "MyInterface001" )
    //
    // In practice, the shared header file defines the interface (IInterface) and version name ("MyInterface001")
    // so that each component can use these names/vtables to communicate
    //
    // A single class can support multiple interfaces through multiple inheritance
    //
    // Use this if you want to write the factory function.
    #if !defined(_STATIC_LINKED) || !defined(_SUBSYSTEM)
    #define EXPOSE_INTERFACE_FN(functionName, interfaceName, versionName) \
        static InterfaceReg __g_Create##interfaceName##_reg(functionName, versionName);
    #else
    #define EXPOSE_INTERFACE_FN(functionName, interfaceName, versionName) \
        namespace _SUBSYSTEM \
        {	\
            static InterfaceReg __g_Create##interfaceName##_reg(functionName, versionName); \
        }
    #endif

    #if !defined(_STATIC_LINKED) || !defined(_SUBSYSTEM)
    #define EXPOSE_INTERFACE(className, interfaceName, versionName) \
        static void* __Create##className##_interface() {return static_cast<interfaceName *>( new className );} \
        static InterfaceReg __g_Create##className##_reg(__Create##className##_interface, versionName );
    #else
    #define EXPOSE_INTERFACE(className, interfaceName, versionName) \
        namespace _SUBSYSTEM \
        {	\
            static void* __Create##className##_interface() {return static_cast<interfaceName *>( new className );} \
            static InterfaceReg __g_Create##className##_reg(__Create##className##_interface, versionName ); \
        }
    #endif

    // Use this to expose a singleton interface with a global variable you've created.
    #if !defined(_STATIC_LINKED) || !defined(_SUBSYSTEM)
    #define EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, globalVarName) \
        static void* __Create##className##interfaceName##_interface() {return static_cast<interfaceName *>( &globalVarName );} \
        static InterfaceReg __g_Create##className##interfaceName##_reg(__Create##className##interfaceName##_interface, versionName);
    #else
    #define EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, globalVarName) \
        namespace _SUBSYSTEM \
        { \
            static void* __Create##className##interfaceName##_interface() {return static_cast<interfaceName *>( &globalVarName );} \
            static InterfaceReg __g_Create##className##interfaceName##_reg(__Create##className##interfaceName##_interface, versionName); \
        }
    #endif

    // Use this to expose a singleton interface. This creates the global variable for you automatically.
    #if !defined(_STATIC_LINKED) || !defined(_SUBSYSTEM)
    #define EXPOSE_SINGLE_INTERFACE(className, interfaceName, versionName) \
        static className __g_##className##_singleton; \
        EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, __g_##className##_singleton)
    #else
    #define EXPOSE_SINGLE_INTERFACE(className, interfaceName, versionName) \
        namespace _SUBSYSTEM \
        {	\
            static className __g_##className##_singleton; \
        }	\
        EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, __g_##className##_singleton)
    #endif

    // load/unload components
    class CSysModule;

    // interface return status
    enum 
    {
        IFACE_OK = 0,
        IFACE_FAILED
    };

    //-----------------------------------------------------------------------------
    // UNDONE: This is obsolete, use the module load/unload/get instead!!!
    //-----------------------------------------------------------------------------
    extern CreateInterfaceFn	Sys_GetFactory( CSysModule *pModule );
    extern CreateInterfaceFn	Sys_GetFactory( const char *pModuleName );
    extern CreateInterfaceFn	Sys_GetFactoryThis( void );

    //-----------------------------------------------------------------------------
    // Load & Unload should be called in exactly one place for each module
    // The factory for that module should be passed on to dependent components for
    // proper versioning.
    //-----------------------------------------------------------------------------
    extern CSysModule			*Sys_LoadModule( const char *pModuleName );
    extern void					Sys_UnloadModule( CSysModule *pModule );

    // This is a helper function to load a module, get its factory, and get a specific interface.
    // You are expected to free all of these things.
    // Returns false and cleans up if any of the steps fail.
    bool Sys_LoadInterface(
        const char *pModuleName,
        const char *pInterfaceVersionName,
        CSysModule **pOutModule,
        void **pOutInterface );

    bool Sys_IsDebuggerPresent();

    //-----------------------------------------------------------------------------
    // Purpose: Place this as a singleton at module scope (e.g.) and use it to get the factory from the specified module name.  
    // 
    // When the singleton goes out of scope (.dll unload if at module scope),
    //  then it'll call Sys_UnloadModule on the module so that the refcount is decremented 
    //  and the .dll actually can unload from memory.
    //-----------------------------------------------------------------------------
    class CDllDemandLoader
    {
    public:
                            CDllDemandLoader( char const *pchModuleName );
        virtual				~CDllDemandLoader();
        CreateInterfaceFn	GetFactory();
        void				Unload();

    private:

        char const	*m_pchModuleName;
        CSysModule	*m_hModule;
        bool		m_bLoadAttempted;
    };
}

using namespace bipe;
