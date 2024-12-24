//
// Created by elian on 7/12/2024.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <iostream>

using namespace std;

class User {
public:
    string username;
    string password;
    string fullname;
    string department;
    string company;
    // here AVLTree;

    User(string username, string password, string fullname, string department, string company);
};


#endif //PROJECT_USER_H
