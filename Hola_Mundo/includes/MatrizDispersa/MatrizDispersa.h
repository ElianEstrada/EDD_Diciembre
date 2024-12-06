//
// Created by elian on 5/12/2024.
//

#ifndef HOLA_MUNDO_MATRIZDISPERSA_H
#define HOLA_MUNDO_MATRIZDISPERSA_H

#include "Node.h"

class MatrizDispersa {

    // cabecera horizontal
    Node *cabeH;

    // cabecera Vertical
    Node *cabeV;

    MatrizDispersa();

    // métodos de la Matriz
    bool estaVacia();

    Node *cabeceraHorizontal(int valor);
    Node *cabeceraVertical(int valor);

    void insertarValor(int valor);
};


#endif //HOLA_MUNDO_MATRIZDISPERSA_H
