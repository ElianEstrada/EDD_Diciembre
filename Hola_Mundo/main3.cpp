//
// Created by elian on 5/12/2024.
//

#include <iostream>
#include "includes/Persona.h"

using namespace std;

int main4() {

    // una clase tiene cabecera y cuerpo
    // la cabecera es la definición de la clase *.h
    // el cuerpo es la implementación de la clase *.cpp

    Persona *persona2 = new Persona(); // operador new -> apuntadores -> referencias En Heap
    Persona persona = Persona(); // En Stack

    persona.setNombre("Elian");
    persona.setEdad(24);
    persona.setAltura(1.70);
    persona.setGenero('M');

    cout << "Nombre: " << persona.getNombre() << " Edad: " << persona.getEdad()
        << " Altura: " << persona.getAltura() << " Genero: " << persona.getGenero() << endl;

    persona.comer();
    persona.saludar();
    persona.estudiarEDD();

    cout << "=======================================" << endl;

    persona2->setNombre("Saúl");
    persona2->setEdad(23);
    persona2->setAltura(1.69);
    persona2->setGenero('M');

    cout << "Nombre: " << persona2->getNombre() << " Edad: " << persona2->getEdad()
         << " Altura: " << persona2->getAltura() << " Genero: " << persona2->getGenero() << endl;

    persona2->comer();
    persona2->saludar();
    persona2->estudiarEDD();

    // Diferentes tipos de Memoria
    // Stack & Heap

    // Stack -> es más pequeño memoria estática
    // Heap -> es más grande memoria dinámica

    cout << "=============================" << endl;

    cout << &persona << endl;
    cout << persona2 << endl;

    persona.setNombre("Alcachofas");
    persona2->setNombre("Ermenegildo");

    cout << &persona << endl;
    cout << persona2 << endl;

    persona2 = &persona;

    cout << persona2 << endl;
    cout << &persona << endl;

    persona.setNombre("Maria");

    cout << persona.getNombre() << endl;
    cout << persona2->getNombre() << endl;

    Persona persona3 = persona;

    persona3.setNombre("Juan");

    cout << persona.getNombre() << endl;
    cout << persona3.getNombre() << endl;

    return 0;
}
