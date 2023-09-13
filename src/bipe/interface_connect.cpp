#include "bipe/interface.hpp"
#include "tier1/convar.h"
#include "icvar.h"

void bipe::ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    g_pCVar = (ICvar*)interfaceFactory(CVAR_INTERFACE_VERSION, NULL);
    bipe::s_nDLLIdentifier = g_pCVar->AllocateDLLIdentifier();
}
