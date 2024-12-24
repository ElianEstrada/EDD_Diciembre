//
// Created by elian on 12/12/2024.
//

#ifndef HOLA_MUNDO_NODEAVL_H
#define HOLA_MUNDO_NODEAVL_H


class NodeAVL {
public:
    int valor;
    int factorEq;
    NodeAVL *izq;
    NodeAVL *der;

    NodeAVL(int valor);
};


#endif //HOLA_MUNDO_NODEAVL_H
