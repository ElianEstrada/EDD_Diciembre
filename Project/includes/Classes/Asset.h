//
// Created by elian on 7/12/2024.
//

#ifndef PROJECT_ASSET_H
#define PROJECT_ASSET_H

#include <iostream>

using namespace std;

class Asset {
public:
    string id;
    string name;
    string description;

    Asset(string name, string description);
    string generateID();
};


#endif //PROJECT_ASSET_H
