#include "pch.h"

#include "Controlador.h"

using namespace System;

int main()
{
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    srand(time(nullptr));

    Controlador* controlador = new Controlador();
    controlador->iniciar_juego();
    return 0;
}
