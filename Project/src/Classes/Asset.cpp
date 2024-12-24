//
// Created by elian on 7/12/2024.
//

#include "../../includes/Classes/Asset.h"

Asset::Asset(string name, string description) {
    this->id = generateID();
    this->name = name;
    this->description = description;
}

string Asset::generateID() {
    return  to_string(random()).substr(0, 3) +
            this->name.substr(0, 3) + to_string(random()).substr(3, 5) +
            this->description.substr(0, 4);
}