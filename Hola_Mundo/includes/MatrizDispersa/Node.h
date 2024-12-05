//
// Created by elian on 5/12/2024.
//

#ifndef HOLA_MUNDO_NODE_H
#define HOLA_MUNDO_NODE_H


class Node {
    // Valor
    int valor;
    // 6 apuntadores
    Node *sig;
    Node *prev;

    Node *arriba;
    Node *abajo;

    Node *adelante;
    Node *atras;

    Node(int valor);
};


#endif //HOLA_MUNDO_NODE_H
