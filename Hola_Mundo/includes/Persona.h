//
// Created by elian on 5/12/2024.
//

#ifndef HOLA_MUNDO_PERSONA_H
#define HOLA_MUNDO_PERSONA_H

#include <iostream>

class Persona {
private:
    //atributos
    std::string nombre;
    int edad;
    char genero;
    float altura;

public:
    Persona();
    ~Persona();

    //métodos
    void comer();
    void saludar();
    void estudiarEDD();

    // getters & setters;
    void setNombre(std::string nombre);
    void setEdad(int edad);
    void setGenero(char genero);
    void setAltura(float altura);

    std::string getNombre();
    int getEdad();
    char getGenero();
    float getAltura();
};


#endif //HOLA_MUNDO_PERSONA_H
