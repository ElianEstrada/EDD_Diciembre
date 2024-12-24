//
// Created by elian on 7/12/2024.
//

#ifndef PROJECT_TRANSACTION_H
#define PROJECT_TRANSACTION_H

#include <iostream>
#include "User.h"

using namespace std;

class Transaction {
public:
    string id;
    string idAsset;
    User *user;
    string date;
    string rentTime;

    Transaction(string idAsset, User *user, string rentTime);
    string generateID();
};


#endif //PROJECT_TRANSACTION_H
