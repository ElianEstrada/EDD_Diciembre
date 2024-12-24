//
// Created by elian on 12/12/2024.
//

#include <iostream>
#include "../../includes/Tree/AVL.h"

AVL::AVL() {
    this->raiz = nullptr;
}

void AVL::insertar(int valor) {
    NodeAVL *node = new NodeAVL(valor);

    insertar(node, this->raiz);
}

void AVL::insertar(NodeAVL *valor, NodeAVL *&raiz) {

    if (raiz == nullptr) {
        raiz = valor;
        raiz->factorEq = factEquilibrio(raiz);
        return;
    }

    if(valor->valor < raiz->valor) {
        insertar(valor, raiz->izq);
    } else {
        insertar(valor, raiz->der);
    }

    raiz->factorEq = factEquilibrio(raiz);

    if(raiz->factorEq < -1) {
        if(raiz->izq->factorEq > 0) {
            rotacionID(raiz);
            return;
        }

        rotacionD(raiz);
        return;
    }

    if (raiz->factorEq > 1) {
        if (raiz->der->factorEq < 0) {
            rotacionDI(raiz);
            return;
        }

        rotacionI(raiz);
    }
}

void AVL::eliminar(int valor){

    eliminar(valor, this->raiz);
}

void AVL::eliminar(int valor, NodeAVL* &raiz) {

    if (raiz == nullptr) {
        std::cout << "El valor: " + std::to_string(valor) + " no existe" << std::endl;
        return;
    }

    if (valor == raiz->valor) {
        // Eliminar raíz
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

        // Buscar él más a la derecha del hijo izquierdo
        NodeAVL *nodeDer = masDerecha(raiz->izq);
        raiz->valor = nodeDer->valor;

        eliminar(nodeDer->valor, raiz->izq);

        valor = raiz->valor;
    }

    if (valor < raiz->valor) {
        eliminar(valor, raiz->izq);
    }

    if(valor > raiz->valor) {
        eliminar(valor, raiz->der);
    }

    raiz->factorEq = factEquilibrio(raiz);

    if(raiz->factorEq < -1) {
        if(raiz->izq->factorEq > 0) {
            rotacionID(raiz);
            return;
        }

        rotacionD(raiz);
        return;
    }

    if(raiz->factorEq > 1) {
        if(raiz->der->factorEq < 0) {
            rotacionDI(raiz);
            return;
        }

        rotacionI(raiz);
        return;
    }
}

void AVL::rotacionD(NodeAVL *&node) {

    NodeAVL *aux = node->izq;

    node->izq = aux->der;
    aux->der = node;
    node = aux;

    node->factorEq = factEquilibrio(node);
    node->der->factorEq = factEquilibrio(node->der);

    if(node->izq == nullptr) return;

    node->izq->factorEq = factEquilibrio(node->izq);
}

void AVL::rotacionI(NodeAVL *&node) {
    NodeAVL *aux = node->der;

    node->der = aux->izq;
    aux->izq = node;
    node = aux;

    node->factorEq = factEquilibrio(node);
    node->izq->factorEq = factEquilibrio(node->izq);

    if (node->der == nullptr) return;

    node->der->factorEq = factEquilibrio(node->der);
}

void AVL::rotacionDI(NodeAVL *&node) {
    rotacionD(node->der);
    rotacionI(node);
}

void AVL::rotacionID(NodeAVL *&node) {
    rotacionI(node->izq);
    rotacionD(node);
}

NodeAVL *AVL::masDerecha(NodeAVL* &node){
    if(node->der == nullptr) {
        return node;
    }

    return masDerecha(node->der);
}

int AVL::alturaMax(NodeAVL *node) {

    if (node == nullptr) return 0;

    int hizq = alturaMax(node->izq);
    int hder = alturaMax(node->der);

    return hizq > hder ? hizq + 1 : hder + 1;
}

int AVL::factEquilibrio(NodeAVL *node) {
    return alturaMax(node->der) - alturaMax(node->izq);
}

bool AVL::esHoja(NodeAVL *node) {
    return node->izq == nullptr && node->der == nullptr;
}

std::string AVL::imprimir() {

    int count = -1;
    std::string dot = "digraph G {\n\tnode [shape=circle];\n\t";

    dot += imprimir(this->raiz, count);

    dot += "\n}";

    return dot;
}

std::string AVL::imprimir(NodeAVL *raiz, int &count) {
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