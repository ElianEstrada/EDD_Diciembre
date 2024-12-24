//
// Created by elian on 9/12/2024.
//

#ifndef PROJECT_SPARSEMATRIX_H
#define PROJECT_SPARSEMATRIX_H

#include "Node.h"
#include "../Classes/User.h"

class SparseMatrix {
public:
    Node *headH;
    Node *headV;

    SparseMatrix();

    bool isEmpty();

    Node *searchDepartment(string department);
    Node *searchCompany(string company);

    Node *insertDepartment(string department);
    Node *insertCompany(string company);

    void insertUser(User *user);
    void insertLast(Node *user, Node *department, Node *company);
    void insertLastDepartment(Node *user, Node *department);
    void insertLastCompany(Node *user, Node *company);
    void insertBetweenDepartment(Node *user, Node *down);
    void insertBetweenCompany(Node *user, Node *next);

    Node *itsDepartment(Node *node);
    Node *itsCompany(Node *node);

    bool mostRight(Node *department, string &departmentName);
    bool mostDown(Node *company, string &companyName);

    string report();
};


#endif //PROJECT_SPARSEMATRIX_H
