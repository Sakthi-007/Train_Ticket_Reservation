//
// Created by SakthiVignesh on 16-07-2025.
//

#ifndef CABIN_H
#define CABIN_H
#include <bits/stdc++.h>
using namespace std;

class cabin {
private:
vector<pair<string,bool>>seats={{"UPPER1",false},{"UPPER2",false},{"LOWER1",false},{"LOWER2",false},{"MIDDLE1",false},{"MIDDLE2",false},{"SIDEU",false},{"SIDEL",false}
    ,{"SIDELRAC",false}};
public:
    friend class Train; // Allow Train class to access private members
    void getInfo() ;
    vector<pair<string,bool>>getSeats()const{return seats;}

};



#endif //CABIN_H
