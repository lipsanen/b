#pragma once

#include "bob/tier1/interface.h"

namespace bob
{
    void ConnectInterfaces(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory);
}

using namespace bob;
