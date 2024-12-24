//
// Created by elian on 5/12/2024.
//

#include <iostream>
#include "includes/MatrizDispersa/MatrizDispersa.h"

using namespace std;

int main5() {

    MatrizDispersa *matriz = new MatrizDispersa();

    matriz->insertarValor(5, 0, 0);
    matriz->insertarValor(8, 1, 0);
    matriz->insertarValor(10, 2, 1);
    matriz->insertarValor(15, 1, 1);

    return 0;
}