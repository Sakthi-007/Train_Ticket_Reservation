//
// Created by SakthiVignesh on 16-07-2025.
//

#include "cabin.h"

void cabin::getInfo() {
        cout << "Cabin Information:" << endl;

    for (const auto& seat : seats) {

        if (seat.first=="SIDELRAC")continue;
            cout << "Seat " << seat.first << ": " << (seat.second ? "Occupied" : "Available") << endl;
        }
    }



