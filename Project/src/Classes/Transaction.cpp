//
// Created by elian on 7/12/2024.
//

#include "../../includes/Classes/Transaction.h"

Transaction::Transaction(std::string idAsset, User *user, std::string rentTime) {
    this->id = generateID();
    this->idAsset = idAsset;
    this->user = user;
    this->date = "27-12-2024";
    this->rentTime = rentTime;
}

string Transaction::generateID() {
    return  to_string(random()).substr(0, 3) +
            this->idAsset.substr(5, 5) + to_string(random()).substr(3, 5) +
            this->user->username.substr(0, 4);
}