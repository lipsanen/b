#pragma once

#include "tier1/interface.h"

namespace bob
{
    void ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory);
}
