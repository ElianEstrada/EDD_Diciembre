#include <iostream>

using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main2() {

    short num1; // Cuanta memoria ocupa? 2 bytes -> 16 bits;
    int num; // Cuanta memoria ocupa? 4 bytes -> 32 bits;
    long num2; // Cuanta memoria ocupa? 8 bytes -> 64 bits;

    int vector[1000]; // Cuanta memoria ocupa este vector? -> 40 bytes -> 320 bits;

    vector[1] = 10; // 2 bits -> 10-> 2 | 10 -> 2

    cout << vector << endl; // 10 -> 0 * tam + dir -> dir_nueva
    cout << &vector[1] << endl; // O(1)
    cout << &vector[2] << endl; // O(1)

    // |_|_|_|_| - |_|_|_|_| - |_|_|_|_| Secuencia en memoria.
    //  0           1           2


    // mapeo lexicográfico
    int matriz[5][5]; // 5 * 5 = 25 * 4 = 100 bytes;

    /*
     * |_|_|_|_| 1 -> 1, 2
     * |_|_|_|_| 2 -> 3, 3
     * |_|_|_|_| 3
     *  1 2 3 4
     *
     *  |_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|-|_|_|_|_|
     * */

    // Matriz Dispersa - EDD Dinámica
    // Solo ocupo el espacio que utilizo
    // Se pierde la indexación.

    // Creamos Nodos enlazados.

    // |_|->|_|->|_| -> Cabeceras Horizontales
    //  |    |    |
    // |_|->|_|->|_|
    //  |
    // Cabeceras verticales

    //  0    5   250
    return 0;
}