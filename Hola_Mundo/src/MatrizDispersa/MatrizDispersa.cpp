//
// Created by elian on 5/12/2024.
//

#include "../../includes/MatrizDispersa/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(){
    this->cabeH = nullptr;
    this->cabeV = nullptr;
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

// Se crea el usuario
// el usuario tiene asociado un departamento y una empresa
// se deben buscar el depa y la empresa y si no existe crearlas.
