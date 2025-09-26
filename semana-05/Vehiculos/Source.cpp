#include "pch.h"
#include <iostream>
#include "Carro.h"
#include "Moto.h"


int main()
{
    srand(time(nullptr));

    bool gameOver = false;
    Moto* moto = new Moto(4, 10);
    Carro* carro = new Carro(2, 30);

    while (gameOver == false) {
        moto->mostrar();
        carro->mostrar();

        if (moto->llegoMeta()) {
            gameOver = true;
            Console::SetCursorPosition(10, 1);
            cout << "HA GANADO LA MOTO";
        }

        if (carro->llegoMeta()) {
            gameOver = true;
            Console::SetCursorPosition(10, 1);
            cout << "HA GANADO EL CARRO";
        }

        _sleep(100);
        moto->borrar();
        carro->borrar();

        moto->mover();
        carro->mover();

    }

    return 0;
}
