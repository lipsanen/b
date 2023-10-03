#pragma once

#include "tier1/interface.h"

namespace bipe
{
    void ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory);
    int sdk_version();
}

using namespace bipe;
