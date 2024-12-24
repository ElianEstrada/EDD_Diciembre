//
// Created by elian on 10/12/2024.
//

#include <iostream>
#include "../../includes/Tree/ABB.h"

ABB::ABB() {
    this->raiz = nullptr;
}

void ABB::insertar(int valor) {
    NodeABB *newNode = new NodeABB(valor);

    insertar(newNode, this->raiz);
}

void ABB::insertar(NodeABB *valor, NodeABB* &raiz){
    if (raiz == nullptr) {
        raiz = valor;
        return;
    }

    if(valor->valor < raiz->valor) {
        insertar(valor, raiz->izq);
    } else {
        insertar(valor, raiz->der);
    }
}

void ABB::eliminar(int valor) {
    eliminar(valor, this->raiz);
}

void ABB::eliminar(int valor, NodeABB* &raiz) {

    if (valor == raiz->valor) {
        if(esHoja(raiz)) {
            raiz = nullptr;
            return;
        }

        if(raiz->izq == nullptr) {
            raiz = raiz->der;
            return;
        }

        if (raiz->der == nullptr) {
            raiz = raiz->izq;
            return;
        }
      // 15    17  null   15   12   13
        raiz->der->izq = raiz->izq->der;
      // 15    17   13   15   12   13

      // 15    12  13     15   17
        raiz->izq->der = raiz->der;
      // 15    12   17    15    17

      // 15     15    12
        raiz = raiz->izq;
      // 12     12    null
      return;
    }

    if (valor < raiz->valor) {
        eliminar(valor, raiz->izq);
        return;
    }

    if (valor >= raiz->valor) {
        eliminar(valor, raiz->der);
        return;
    }
}

bool ABB::esHoja(NodeABB *node) {
    return node->izq == nullptr && node->der == nullptr;
}

std::string ABB::imprimir() {

    int count = -1;
    std::string dot = "digraph G {\n\tnode [shape=circle];\n\t";

    dot += imprimir(this->raiz, count);

    dot += "\n}";

    return dot;
}

std::string ABB::imprimir(NodeABB *raiz, int &count) {
    count++;

    int currentCount = count;

    std::string dot = "n" + std::to_string(currentCount) + " [label=" + std::to_string(raiz->valor) + "];\n\t";

    if (esHoja(raiz)) {
        return dot;
    }

    if (raiz->izq != nullptr) {
        int nextNode = count + 1;
        dot += "n" + std::to_string(currentCount) + " -> n" + std::to_string(nextNode) + ";\n\t" + imprimir(raiz->izq, count);
    }

    if (raiz->der != nullptr) {
        int nextNode = count + 1;
        dot += "n" + std::to_string(currentCount) + " -> n" + std::to_string(nextNode) + ";\n\t" + imprimir(raiz->der, count);
    }

    return dot;
}