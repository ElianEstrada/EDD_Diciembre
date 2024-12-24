//
// Created by elian on 12/12/2024.
//

#include "../../includes/Tree/NodeAVL.h"

NodeAVL::NodeAVL(int valor) {
    this->valor = valor;
    this->factorEq = 0;
    this->izq = nullptr;
    this->der = nullptr;
}
