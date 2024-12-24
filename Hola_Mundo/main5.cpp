//
// Created by elian on 10/12/2024.
//

#include <iostream>
#include <fstream>
#include "./includes/Tree/AVL.h"

using namespace std;

int main() {

    auto *arbol = new AVL();

    arbol->insertar(10);
    arbol->insertar(5);
    arbol->insertar(4);
    arbol->insertar(1);
    arbol->insertar(3);
    arbol->insertar(0);
    arbol->insertar(6);
    arbol->insertar(12);
    arbol->insertar(14);
    arbol->insertar(11);

    arbol->eliminar(10);
    arbol->eliminar(3);
    arbol->eliminar(12);
    arbol->eliminar(6);

    std::string path = "/mnt/d/Documentos/Elian/2024/Usac/Vacaciones_Diciembre/Curso/Clase1/Hola_Mundo/";
    //string path = "";

    std::ofstream file(path + "arbolAVL.dot");

    if (!file) {
        std::cout << "error" << std::endl;
    }

    file << arbol->imprimir();
    file.close();

    std::string command = "dot -Tsvg " + path + "arbolAVL.dot" + " -o " + path + "arbolAVL.svg";

    system(command.c_str());

    command = "feh " + path + "arbolAVL.svg";
    system(command.c_str());

    return 0;
}