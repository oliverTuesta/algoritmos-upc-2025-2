#include "pch.h"
#include "Juego.h"
#include <cstdlib>

using namespace System;

int main()
{
    srand(time(nullptr));
    Console::CursorVisible = false;
    Console::SetWindowSize(ANCHO, ALTO+2);
    Juego* juego = new Juego();
    juego->iniciar_juego();

    return 0;
}
