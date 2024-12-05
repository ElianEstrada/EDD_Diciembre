//
// Created by elian on 5/12/2024.
//

#include <iostream>

using namespace std;

void suma(int a, int b) {
    // creando una copia de las variables por valor
    // a = a_vieja -> 10 -> nueva variable con otra dierección de memoria.
    // b = b_vieja -> 20 -> nueva variable con otra dierección de memoria.

    a = a + b; // no es la misma a_vieja
    cout << &a << endl;
    cout << "El resultado de la suma es: " << a << endl;
}

void suma2(int &a, int b) {
    // estoy utilizando la misma variable a -> a_vieja
    a = a + b;
    cout << &a << endl;
    cout << "El resultado de la suma es: " << a << endl;
}

int main3() {

    // Punteros -> Apuntadores

    // Apuntador de Indirección (*) y Apuntador de Dirección (&)

    int num=10; // -> 4 bytes -- 0x7ffd5e56a744 -> 1 byte ||||||||||1|0|1|0|

    cout << &num << endl;

    int *numP; // puntero -> se le tiene que asignar una dirección de memoria

    numP = &num; // Estamos copiando la dirección, asignación por referencia.
    cout << numP << endl;
    cout << *numP << endl;

    *numP = 20;

    cout << num << endl;

    // Referencia y Valor

    int num2 = num; // asignación por valor, una copia del valor, más no de la dirección
    cout << num2 << endl;
    num2 = 40;
    cout << num2 << endl;
    cout << num << endl;

    num = 30;

    cout << num2 << endl;       // 40
    cout << num << endl;        // 30
    cout << *numP << endl;      // 30

    cout << &num << endl;
    cout << &num2 << endl;


    // Parametros por valor y referencia

    int a = 10;
    int b = 20;

    cout << &a << endl;
    suma(a, b);
    cout << "valor a: " << a << endl;
    cout << "valor b: " << b << endl;

    cout << &a << endl;
    suma2(a, b);
    cout << "Valor a: " << a << endl;
    cout << "Valor b: " << b << endl;

    return 0;
}
