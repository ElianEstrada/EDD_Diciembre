//
// Created by elian on 5/12/2024.
//

#include "../includes/Persona.h"

// para implementar un metodo
// <tipo> <nombre_clase>::<metodo>

Persona::Persona() {

}

Persona::~Persona() {
    delete this;
}

void Persona::comer() {
    std::cout << "Estoy comiendo" << std::endl;
}

void Persona::saludar() {
    std::cout << "Estoy saludando" << std::endl;
}

void Persona::estudiarEDD() {
    std::cout << "Estoy estudiando EDD" << std::endl;
}

void Persona::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setAltura(float altura) {
    this->altura = altura;
}

void Persona::setGenero(char genero) {
    this->genero = genero;
}

std::string Persona::getNombre() {
    return this->nombre;
}

int Persona::getEdad() {
    return this->edad;
}

float Persona::getAltura() {
    return this->altura;
}

char Persona::getGenero() {
    return this->genero;
}