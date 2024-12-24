cmake_minimum_required(VERSION 3.22)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project main.cpp
        includes/Classes/User.h
        src/Classes/User.cpp
        includes/Classes/Asset.h
        src/Classes/Asset.cpp
        includes/Classes/Transaction.h
        src/Classes/Transaction.cpp
        includes/SparseMatrix/Node.h
        src/SparceMatrix/Node.cpp
        includes/SparseMatrix/SparseMatrix.h
        src/SparceMatrix/SparseMatrix.cpp)
