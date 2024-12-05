//
// Created by elian on 5/12/2024.
//

#include "../../includes/MatrizDispersa/Node.h"

Node::Node(int valor) {
    this->valor=valor;
    this->sig = nullptr;
    this->prev = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}
