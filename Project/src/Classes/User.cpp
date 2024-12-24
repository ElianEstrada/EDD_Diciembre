//
// Created by elian on 7/12/2024.
//

#include "../../includes/Classes/User.h"

User::User(std::string username, std::string password, std::string fullname, std::string department,
           std::string company) {
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->department = department;
    this->company = company;

    // here initialize AVLTree
}