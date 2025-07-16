//
// Created by SakthiVignesh on 16-07-2025.
//

#include "coach.h"

void coach::getCabins() {
    for (auto i:cabins) {
        i->getInfo();
    }
}

void coach::addCabin(cabin *c) {
    cabins.push_back(c);
}


