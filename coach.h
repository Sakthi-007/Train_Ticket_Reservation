//
// Created by SakthiVignesh on 16-07-2025.
//

#ifndef COACH_H
#define COACH_H
#include "cabin.h"
#include <bits/stdc++.h>
using namespace std;


class coach {
private:
    vector<cabin*>cabins;
public:
    void getCabins();
    void addCabin(cabin *c);
    vector<cabin*> getCabinsList()const {return cabins;};
};



#endif //COACH_H
