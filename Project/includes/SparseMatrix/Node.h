//
// Created by elian on 9/12/2024.
//

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

#include "../Classes/User.h"

class Node {
public:
    User *user;
    Node *next;
    Node *prev;
    Node *up;
    Node *down;
    Node *ahead;
    Node *behind;
    string header;

    // attributes for report
    static int countGroup;
    static int countNode;

    int group;
    int id;

    explicit Node(User *user);
    explicit Node(string &header, bool flag=false);
};


#endif //PROJECT_NODE_H
