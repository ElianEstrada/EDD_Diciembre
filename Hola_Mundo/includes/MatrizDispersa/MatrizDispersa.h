//
// Created by elian on 5/12/2024.
//

#ifndef HOLA_MUNDO_MATRIZDISPERSA_H
#define HOLA_MUNDO_MATRIZDISPERSA_H

#include "Node.h"

class MatrizDispersa {
public:
    // cabecera horizontal
    Node *cabeH;

    // cabecera Vertical
    Node *cabeV;

    MatrizDispersa();

    // métodos de la Matriz
    bool estaVacia();

    Node *cabeceraHorizontal(int valor);
    Node *cabeceraVertical(int valor);

    Node *insertarCabeceraH(int valor);
    Node *insertarCabeceraV(int valor);

    void insertarValor(int valor, int cabH, int cabV);
    void insertarAlFinal(Node *valor, Node *cabeH, Node *cabeV);
    void insertarAlFinalH(Node *valor, Node *cabeH);
    void insertarAlFinalV(Node *valor, Node *cabeV);
    void insertarAlMedioH(Node *valor, Node *horizontal);
    void insertarAlMedioV(Node *valor, Node *vertical);

    Node *enCabeceraH(Node *node);
    Node *enCabeceraV(Node *node);

    bool masAbajo(Node *cabeV, int cabH);
    bool masDerecha(Node *cabeH, int cabV);

    void reporte();
};


#endif //HOLA_MUNDO_MATRIZDISPERSA_H
