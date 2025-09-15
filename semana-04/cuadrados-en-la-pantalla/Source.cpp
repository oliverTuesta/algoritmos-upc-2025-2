#include "pch.h"
#include "VectorCuadrado.h"
#include "conio.h"

int main()
{
    srand(time(nullptr));
    Console::SetWindowSize(ANCHO+5, ALTO+5);
    Console::CursorVisible = false;
    bool gameOver = false;

    VectorCuadrado* vec = new VectorCuadrado();

    while (gameOver == false) {
        
        char tecla;
        if (_kbhit()) {
            tecla = _getch();

            if (tecla == 'a') {
                Cuadrado *c = new Cuadrado();
                vec->addElemento(c);
            }

            if (tecla == 'c') {
                for (int i = 0; i < vec->getCantidad(); i++) {
                    Cuadrado* c = vec->getElemento(i);
                    c->cambiarColorRandom();
                }
            }

            if (tecla == 'e') {
                vec->deleteElemento(0);
            }
        }

        for (int i = 0; i < vec->getCantidad(); i++) {
            Cuadrado* c = vec->getElemento(i);
            c->desplazar();
            c->mostrar();
        }

        _sleep(100);
        for (int i = 0; i < vec->getCantidad(); i++) {
            Cuadrado* c = vec->getElemento(i);
            c->borrar();
        }
    }

    return 0;
}
