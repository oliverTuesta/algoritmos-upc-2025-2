#include "pch.h"

#include "Controlador.h"

using namespace System;

int main()
{
    srand(time(0));
    Console::CursorVisible = false;
    Console::SetWindowSize(ANCHO_PANTALLA, ALTO_PANTALLA);

    Controlador* cont = new Controlador();
    cont->iniciar_juego();
    return 0;
}
