#pragma once

#include "tier1/interface.h"

namespace bipe
{
    void ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory);
}

using namespace bipe;
