//
// Created by elian on 9/12/2024.
//

#include "../../includes/SparseMatrix/SparseMatrix.h"

SparseMatrix::SparseMatrix() {
    this->headH = nullptr;
    this->headV = nullptr;
}

void SparseMatrix::insertUser(User *user) {

    Node *dept = nullptr;
    Node *comp = nullptr;

    Node *newUser = new Node(user);

    string department = user->department;
    string company = user->company;

    if(isEmpty()) {
        dept = insertDepartment(department);
        comp = insertCompany(company);

        insertLast(newUser, dept, comp);

        return;
    }

    dept = searchDepartment(department);
    comp = searchCompany(company);

    if (dept == nullptr && comp == nullptr) {
        dept = insertDepartment(department);
        comp = insertCompany(company);

        insertLast(newUser, dept, comp);

        return;
    }

    if (dept == nullptr) {
        dept = insertDepartment(department);

        insertLast(newUser, dept, comp);

        return;
    }

    if (comp == nullptr) {
        comp = insertCompany(company);

        insertLast(newUser, dept, comp);

        return;
    }

    Node *auxDepartment = dept->down;
    Node *userCompany = nullptr;
    bool down = false;

    while (auxDepartment != nullptr) {
        userCompany = itsCompany(auxDepartment);
        down = mostDown(userCompany, company);

        if (!down) break;

        auxDepartment = auxDepartment->down;
    }

    if(down) {
        insertLastDepartment(newUser, dept);
    } else {
        insertBetweenDepartment(newUser, auxDepartment);
    }

    Node *auxCompany = comp->next;
    Node *userDepartment = nullptr;
    bool next = false;

    while (auxCompany != nullptr) {
        userDepartment = itsDepartment(auxCompany);
        next = mostRight(userDepartment, department);

        if (!next) break;

        auxCompany = auxCompany->next;
    }

    if (next) {
        insertLastCompany(newUser, comp);
    } else {
        insertBetweenCompany(newUser, auxCompany);
    }
}

void SparseMatrix::insertLast(Node *user, Node *department, Node *company) {
    insertLastDepartment(user, department);
    insertLastCompany(user, company);
}

void SparseMatrix::insertLastDepartment(Node *user, Node *department) {
    user->group = department->group;

    Node *aux = department;

    while (aux->down != nullptr) {
        aux = aux->down;
    }

    aux->down = user;
    user->up = aux;
}

void SparseMatrix::insertLastCompany(Node *user, Node *company) {
    Node *aux = company;

    while(aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = user;
    user->prev = aux;
}

void SparseMatrix::insertBetweenDepartment(Node *user, Node *down) {
    user->group = down->group;

    down->up->down = user;
    user->down = down;
    user->up = down->up;
    down->up = user;
}

void SparseMatrix::insertBetweenCompany(Node *user, Node *next) {
    next->prev->next = user;
    user->next = next;
    user->prev = next->prev;
    next->prev = user;
}

Node *SparseMatrix::insertDepartment(std::string department) {

    Node *newDepartment = new Node(department, true);

    if(this->headH == nullptr) {
        this->headH = newDepartment;

        return newDepartment;
    }

    Node *aux = this->headH;

    while (aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = newDepartment;
    newDepartment->prev = aux;

    return newDepartment;
}

Node *SparseMatrix::insertCompany(std::string company) {

    Node *newCompany = new Node(company);

    if(this->headV == nullptr) {
        this->headV = newCompany;

        return newCompany;
    }

    Node *aux = this->headV;

    while (aux->down != nullptr) {
        aux = aux->down;
    }

    aux->down = newCompany;
    newCompany->up = aux;

    return newCompany;
}

Node *SparseMatrix::searchDepartment(std::string department) {
    if(isEmpty()) return nullptr;

    Node *aux = this->headH;

    while (aux != nullptr) {
        if (aux->header == department) return aux;

        aux = aux->next;
    }

    return nullptr;
}

Node *SparseMatrix::searchCompany(std::string company) {

    if (isEmpty()) return nullptr;

    Node *aux = this->headV;

    while (aux != nullptr) {
        if(aux->header == company) return aux;

        aux = aux->down;
    }

    return nullptr;
}

Node *SparseMatrix::itsDepartment(Node *node) {
    Node *aux = node;

    while(aux->up != nullptr) {
        aux = aux->up;
    }

    return aux;
}

Node *SparseMatrix::itsCompany(Node *node) {
    Node *aux = node;

    while (aux->prev != nullptr) {
        aux = aux->prev;
    }

    return aux;
}

bool SparseMatrix::mostRight(Node *department, std::string &departmentName) {
    Node *aux = department;

    while (aux != nullptr) {
        if (aux->header == departmentName) return true;

        aux = aux->next;
    }

    return false;
}

bool SparseMatrix::mostDown(Node *company, std::string &companyName) {

    Node *aux = company;

    while (aux != nullptr) {
        if (aux->header == companyName) return true;

        aux = aux->down;
    }

    return false;
}

bool SparseMatrix::isEmpty() {
    return this->headH == nullptr;
}

string SparseMatrix::report() {

    string dot = "digraph G {\n\tbgcolor=\"#1a1a1a\";\n\tfontcolor=white;\n\tlabel=\"Sparse Matrix\";\n\t"
                 "labelloc=t;\n\tnodesep=0.5;\n\tnode [shape=box width=1.2 style=filled fillcolor=\"#313638\" fontcolor=white "
                 "color=transparent];\n\tedge [fontcolor=white color=\"#ff5400\"];\n\n\tn0 [shape=point style=invis group=0];\n\n\t";

    if(isEmpty()) {
        dot += "}";

        return dot;
    }

    // Create Nodes to Departments
    Node *department = this->headH;
    Node *users;
    dot += "n0 -> n" + to_string(department->id) + " -> n0 [color=transparent];\n\t";

    string ranks = "{ rank=same; n0; ";
    while (department != nullptr) {
        dot += "n" + to_string(department->id) + " [label=\"" + department->header + "\" group=" + to_string(department->group) + "];\n\t";

        users = department->down;

        dot += "n" + to_string(department->id) + " -> n" + to_string(users->id) + " -> n" + to_string(department->id) + ";\n\t";
        while (users != nullptr) {
            dot += "n" + to_string(users->id) + " [label=\"" + users->user->username + "\" group=" + to_string(users->group) + "];\n\t";

            if (users->down != nullptr) {
                dot += "n" + to_string(users->id) + " -> n" + to_string(users->down->id) + " -> n" + to_string(users->id) + ";\n\t";
            }

            users = users->down;
        }

        if(department->next != nullptr) {
            dot += "n" + to_string(department->id) + " -> n" + to_string(department->next->id) + " -> n" + to_string(department->id) + ";\n\t";
        }

        ranks += "n" + to_string(department->id) + "; ";

        department = department->next;
    }

    ranks += "}\n\t";

    // Create Nodes to Companies
    Node *company = this->headV;
    dot += "n0 -> n" + to_string(company->id) + " -> n0 [color=transparent];\n\t";

    while (company != nullptr) {
        ranks += "{ rank=same; ";
        dot += "n" + to_string(company->id) + " [label=\"" + company->header + "\" group=" + to_string(company->group) + "];\n\t";
        ranks += "n" + to_string(company->id) + "; ";

        users = company->next;

        dot += "n" + to_string(company->id) + " -> n" + to_string(users->id) + " -> n" + to_string(company->id) + ";\n\t";
        while (users != nullptr) {
            dot += "n" + to_string(users->id) + " [label=\"" + users->user->username + "\" group=" + to_string(users->group) + "];\n\t";

            if (users->next != nullptr) {
                dot += "n" + to_string(users->id) + " -> n" + to_string(users->next->id) + " -> n" + to_string(users->id) + ";\n\t";
            }

            ranks += "n" + to_string(users->id) + "; ";
            users = users->next;
        }

        if (company->down != nullptr) {
            dot += "n" + to_string(company->id) + " -> n" + to_string(company->down->id) + " -> n" + to_string(company->id) + ";\n\t";
        }

        ranks += "}\n\t";
        company = company->down;
    }

    dot += ranks;
    dot += "\n}";

    return dot;
}