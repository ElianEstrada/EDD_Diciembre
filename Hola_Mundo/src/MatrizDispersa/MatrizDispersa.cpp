//
// Created by elian on 5/12/2024.
//

#include <iostream>
#include "../../includes/MatrizDispersa/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(){
    this->cabeH = nullptr;
    this->cabeV = nullptr;
}

void MatrizDispersa::insertarValor(int valor, int cabH, int cabV) {

    Node *cabeH = nullptr;
    Node *cabeV = nullptr;
    Node *usuarioNuevo = new Node(valor);

    if(estaVacia()) {
        cabeH = insertarCabeceraH(cabH);
        cabeV = insertarCabeceraV(cabV);

        insertarAlFinal(usuarioNuevo, cabeH, cabeV);

        return;
    }

    cabeH = cabeceraHorizontal(cabH);
    cabeV = cabeceraVertical(cabV);

    if (cabeH == nullptr && cabeV == nullptr){
        cabeH = insertarCabeceraH(cabH);
        cabeV = insertarCabeceraV(cabV);

        insertarAlFinal(usuarioNuevo, cabeH, cabeV);

        return;
    }

    if (cabeH == nullptr) {
        cabeH = insertarCabeceraH(cabH);

        insertarAlFinal(usuarioNuevo, cabeH, cabeV);

        return;
    }

    if (cabeV == nullptr) {
        cabeV = insertarCabeceraV(cabV);

        insertarAlFinal(usuarioNuevo, cabeH, cabeV);

        return;
    }

    Node *auxH = cabeH->abajo;
    Node *userCabV;
    bool abajo;

    while (auxH != nullptr) {
        userCabV = enCabeceraV(auxH);
        abajo = masAbajo(userCabV, cabV);

        if(!abajo) break;

        auxH = auxH->abajo;
    }

    if(abajo) {
        insertarAlFinalH(usuarioNuevo, cabeH);
    } else {
        insertarAlMedioH(usuarioNuevo, auxH);
    }

    Node *auxV = cabeV->sig;
    Node *userCabH;
    bool siguiente = false;

    while (auxV != nullptr) {
        userCabH = enCabeceraH(auxV);
        siguiente = masDerecha(userCabH, cabH);

        if(!siguiente) break;

        auxV = auxV->sig;
    }

    if(siguiente) {
        insertarAlFinalV(usuarioNuevo, cabeV);
    }else {
        insertarAlMedioV(usuarioNuevo, auxV);
    }
}

void MatrizDispersa::insertarAlFinal(Node *valor, Node *cabeH, Node *cabeV) {
    insertarAlFinalH(valor, cabeH);
    insertarAlFinalV(valor, cabeV);
}

Node *MatrizDispersa::insertarCabeceraH(int valor) {

    Node *nuevaCab = new Node(valor);

    if(this->cabeH == nullptr) {
        this->cabeH = nuevaCab;

        return nuevaCab;
    }

    Node *aux = cabeH;

    while (aux->sig != nullptr) {
        aux = aux->sig;
    }

    aux->sig = nuevaCab;
    nuevaCab->prev = aux;

    return nuevaCab;
}

void MatrizDispersa::insertarAlFinalH(Node *valor, Node *cabeH) {
    Node *aux = cabeH;

    while(aux->abajo != nullptr) {
        aux = aux->abajo;
    }

    aux->abajo = valor;
    valor->arriba = aux;
}

void MatrizDispersa::insertarAlFinalV(Node *valor, Node *cabeV) {

    Node *aux = cabeV;

    while (aux->sig != nullptr) {
        aux = aux->sig;
    }

    aux->sig = valor;
    valor->prev = aux;
}

void MatrizDispersa::insertarAlMedioH(Node *valor, Node *horizontal) {
    horizontal->arriba->abajo = valor;
    valor->abajo = horizontal;
    valor->arriba = horizontal->arriba;
    horizontal->arriba = valor;
}

void MatrizDispersa::insertarAlMedioV(Node *valor, Node *vertical) {
    vertical->prev->sig = valor;
    valor->sig = vertical;
    valor->prev = vertical->prev;
    vertical->prev = valor;
}

Node *MatrizDispersa::insertarCabeceraV(int valor) {

    Node *nuevaCab = new Node(valor);

    if (this->cabeV == nullptr) {
        this->cabeV = nuevaCab;

        return nuevaCab;
    }

    Node *aux = cabeV;

    while (aux->abajo != nullptr) {
        aux = aux->abajo;
    }

    aux->abajo = nuevaCab;
    nuevaCab->arriba = aux;

    return nuevaCab;
}

Node *MatrizDispersa::cabeceraHorizontal(int valor) {

    if (estaVacia()) {
        return nullptr;
    }

    Node *aux = cabeH;

    while(aux != nullptr) {
        if(aux->valor == valor) return aux;

        aux = aux->sig;
    }

    return nullptr;
}

Node *MatrizDispersa::cabeceraVertical(int valor) {

    if (estaVacia()) {
        return nullptr;
    }

    Node *aux = cabeV;

    while (aux != nullptr) {
        if (aux->valor == valor) return aux;

        aux = aux->abajo;
    }

    return nullptr;
}

Node *MatrizDispersa::enCabeceraH(Node *node) {

    Node *aux = node;

    while (aux->arriba != nullptr) {
        aux = aux->arriba;
    }

    return aux;
}

Node *MatrizDispersa::enCabeceraV(Node *node) {

    Node *aux = node;

    while(aux->prev != nullptr) {
        aux = aux->prev;
    }

    return aux;
}

bool MatrizDispersa::masDerecha(Node *cabeH, int cabH) {

    Node *aux = cabeH;

    while (aux != nullptr) {
        if(aux->valor == cabH) return true;

        aux = aux->sig;
    }

    return false;
}

bool MatrizDispersa::masAbajo(Node *cabeV, int cabV) {

    Node *aux = cabeV;

    while (aux != nullptr) {
        if (aux->valor == cabV) return true;

        aux = aux->abajo;
    }

    return false;
}

bool MatrizDispersa::estaVacia() {
    /*if (this->cabeH == nullptr){
        if (this->cabeV == nullptr) {
            return true;
        }
    }

    return false;*/

    return this->cabeH == nullptr;
}

void MatrizDispersa::reporte() {

    int count = 0;
    std::string dot = "digraph G {\nnode[shape=box];\n";

    Node *cabH = this->cabeH;
    Node *cabV = this->cabeV;

    // Cabeceras horizontales
    while (cabH != nullptr) {
        dot += "n" + std::to_string(count) + " [label=\"" + std::to_string(cabH->valor) + "\"];\n";
    }

}

// Se crea el usuario
// el usuario tiene asociado un departamento y una empresa
// se deben buscar el depa y la empresa y si no existe crearlas.
