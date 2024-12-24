//
// Created by elian on 9/12/2024.
//

#include "../../includes/SparseMatrix/Node.h"

int Node::countGroup = 1;
int Node::countNode = 1;

Node::Node(User *user) {
    this->header = "";
    this->user = user;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->ahead = nullptr;
    this->behind = nullptr;
    this->id = countNode++;
    this->group = 0;
}

Node::Node(std::string &header, bool flag) {
    this->header = header;
    this->user = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->ahead = nullptr;
    this->behind = nullptr;
    this->id = countNode++;
    this->group = flag ? countGroup++ : 0;
}
