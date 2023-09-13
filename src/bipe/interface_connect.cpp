#include "bipe/interface.hpp"
#include "bipe/tier1/convar.h"
#include "bipe/icvar.h"

void bipe::ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
    g_pCVar = (ICvar*)interfaceFactory(CVAR_INTERFACE_VERSION, NULL);
    bipe::s_nDLLIdentifier = g_pCVar->AllocateDLLIdentifier();
}
