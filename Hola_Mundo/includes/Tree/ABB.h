//
// Created by elian on 10/12/2024.
//

#ifndef HOLA_MUNDO_ABB_H
#define HOLA_MUNDO_ABB_H

#include "NodeABB.h"

class ABB {
private:
    void insertar(NodeABB *valor, NodeABB* &raiz);
    void eliminar(int valor, NodeABB* &raiz);
    std::string imprimir(NodeABB *raiz, int &count);
public:
    NodeABB *raiz;

    ABB();

    void insertar(int valor);
    void eliminar(int valor);
    bool esHoja(NodeABB *node);
    std::string imprimir();
};


#endif //HOLA_MUNDO_ABB_H
