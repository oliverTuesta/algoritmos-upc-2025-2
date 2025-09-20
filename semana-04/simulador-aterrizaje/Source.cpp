#include "pch.h"
#include "SimulacionAterrizaje.h"

using namespace System;

int main()
{
    srand(time(0));
    SimulacionAterrizaje* simulacion = new SimulacionAterrizaje(3);
    simulacion->comenzar();

    return 0;
}
