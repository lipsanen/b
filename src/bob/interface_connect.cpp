#include "bob/interface.hpp"
#include "tier1/convar.h"
#include "icvar.h"

void ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    g_pCVar = (ICvar*)interfaceFactory(CVAR_INTERFACE_VERSION, NULL);
    bob::s_nDLLIdentifier = g_pCVar->AllocateDLLIdentifier();
}
