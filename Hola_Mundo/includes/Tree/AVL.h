//
// Created by elian on 12/12/2024.
//

#ifndef HOLA_MUNDO_AVL_H
#define HOLA_MUNDO_AVL_H

#include "NodeAVL.h"

class AVL {
private:
    void insertar(NodeAVL *valor, NodeAVL* &raiz);
    void eliminar(int valor, NodeAVL* &raiz);
    int alturaMax(NodeAVL *node);
    int factEquilibrio(NodeAVL *node); // altura hijo derecho - altura hijo izquierdo
    void rotacionD(NodeAVL* &node);
    void rotacionI(NodeAVL* &node);
    void rotacionDI(NodeAVL* &node);
    void rotacionID(NodeAVL* &node);
    NodeAVL *masDerecha(NodeAVL* &node);
    std::string imprimir(NodeAVL *raiz, int &count);
public:
    NodeAVL *raiz;

    AVL();


    void insertar(int valor);
    void eliminar(int valor);

    bool esHoja(NodeAVL *node);
    std::string imprimir();
};


#endif //HOLA_MUNDO_AVL_H
