#include "pch.h"
#include "Controlador.h"

using namespace System;

void mostrar_menu(int x, int y) {

    Console::SetCursorPosition(x, y);
    cout << "1. Iniciar" << endl;
    Console::SetCursorPosition(x, y+1);
    cout << "2. Como jugar" << endl;
    Console::SetCursorPosition(x, y+2);
    cout << "3. Salir" << endl;
}

void mostrar_indicador_opcion(int x, int y, int opcion) {
    Console::SetCursorPosition(x-2, y+opcion);
    cout << "o";
}

void borrar_indicadores(int x, int y) {
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x - 2, y + i);
        cout << " ";
    }
}

int main()
{
    int x = ANCHO / 2 - 10;
    int y = ALTO / 2 - 4;
    srand(time(nullptr));
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;

    int opcion = 0;

    mostrar_menu(x, y);
    mostrar_indicador_opcion(x, y, opcion);

        while (true) {
            if (_kbhit()) {
                char tecla = _getch();
                if (tecla == 72) {
                    if (opcion >= 1) {
                        opcion--;
                    }
                }
                else if (tecla == 80) {
                    if (opcion < 2) {
                        opcion++;
                    }
                }
                else if (tecla == 13) {
                    if (opcion == 0) {
                        Controlador* cont = new Controlador();
                        cont->iniciar_juego();
                    }
                    else if (opcion == 1) {

                    }
                    else if (opcion == 2) {
                        break;
                    }
                    mostrar_menu(x, y);
                }
                borrar_indicadores(x, y);
                mostrar_indicador_opcion(x, y, opcion);
            }

        }

    return 0;
}
