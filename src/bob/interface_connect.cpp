#include "bob/interface.hpp"
#include "bob/tier1/convar.h"
#include "bob/icvar.h"

void bob::ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    g_pCVar = (ICvar*)interfaceFactory(CVAR_INTERFACE_VERSION, NULL);
    bob::s_nDLLIdentifier = g_pCVar->AllocateDLLIdentifier();
}
