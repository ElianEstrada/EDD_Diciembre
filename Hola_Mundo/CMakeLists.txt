cmake_minimum_required(VERSION 3.22)
project(Hola_Mundo)

set(CMAKE_CXX_STANDARD 23)

add_executable(Hola_Mundo main.cpp
        main2.cpp
        main3.cpp
        includes/Persona.h
        src/Persona.cpp
        main4.cpp
        includes/MatrizDispersa/Node.h
        src/MatrizDispersa/Node.cpp
        includes/MatrizDispersa/MatrizDispersa.h
        src/MatrizDispersa/MatrizDispersa.cpp
        includes/Tree/NodeABB.h
        src/Tree/NodeABB.cpp
        includes/Tree/ABB.h
        src/Tree/ABB.cpp
        main5.cpp
        includes/Tree/NodeAVL.h
        src/Tree/NodeAVL.cpp
        includes/Tree/AVL.h
        src/Tree/AVL.cpp
)
