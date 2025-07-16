//
// Created by SakthiVignesh on 16-07-2025.
//

#ifndef TRAIN_H
#define TRAIN_H
#include "coach.h"
#include "cabin.h"
#include "user.h"
#include <bits/stdc++.h>
using namespace std;


class Train {
private:
    string trainName;
    string trainNumber;
    vector<coach*>coaches;
    map<int,vector<user*>>bookings;
    map<int,vector<vector<tuple<user*,cabin*,int>>>>mainallocations;
public:

   static int PNR ; // Initial PNR number
    Train(string name,string number);
    void addCoach(coach* newCoach);
    void getDetailes();
    void bookTicket(user *user);
    bool isPreferenceAvailable(int preference, cabin *cabin);
    string getSeatType(int preference,int age);
    void cancelTicket(int bookingID);
    void displayBookings(int pnr);


};



#endif //TRAIN_H
