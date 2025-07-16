//
// Created by SakthiVignesh on 15-07-2025.
//
#include <bits/stdc++.h>
#include "Train.h"
#include "coach.h"
#include "cabin.h"
#include "user.h"
using namespace std;


user getDetailsOfUsers() {
    cout << "Enter your name: ";
    string name;
    cin>>name;
    cout<<"\nEnter your age:";
    int age;
    cin>>age;
    cout<<"\nEnter your preference (1 for upper, 2 for lower, 3 for middle, 4 for side upper, 5 for side lower):";
    int preference;
    cin>>preference;

    cout<<"\nDo you want to book for a group? (1 for travelling alone,else mention the total group members including you!):";
    int members;
    cin>>members;
    user temp;
    temp.setDetails(name,age,preference,members);
    while (--members) {
        cout << "\nEnter the name of group member: ";
        string groupName;
        cin >> groupName;
        cout << "\nEnter the age of group member: ";
        int groupAge;
        cin >> groupAge;
        cout << "\nEnter the preference of group member (1 for upper, 2 for lower, 3 for middle, 4 for side upper, 5 for side lower): ";
        int groupPreference;
        cin >> groupPreference;

        user *groupMember = new user();
        groupMember->setDetails(groupName, groupAge, groupPreference, 0);
        temp.group.push_back(groupMember);
    }

    return temp;

}



int main() {

    cabin c1,c2;
    coach co1;
    Train train("COVAI EXPRESS","6969");
    co1.addCabin(&c1);
    co1.addCabin(&c2);
    train.addCoach(&co1);

    map<int,user*>bookings;

    bool run=true;

        cout<< "Welcome to the Train Reservation System!" << endl;
    while (run) {
        cout<<"Press 1 to view seats available"<<endl;
        cout<<"Press 2 to book a ticket"<<endl;
        cout<<"Press 3 to cancel the ticket"<<endl;
        cout<<"Press 4 to view Booking details"<<endl;
        cout<<"Press 5 to exit"<<endl;

        int choice;
        cin>>choice;

        switch (choice) {
            case 1: {
                train.getDetailes();
                break;
            }
            case 2:{
                user temp = getDetailsOfUsers();
                train.bookTicket(&temp);
                break;
            }
            case 3:{
                int bookingId;cin>>bookingId;
                train.cancelTicket(bookingId);
                break;
            }
            case 4: {
                int pnr;cin>>pnr;
                train.displayBookings(pnr);
                break;
            }
                case 5: {
                run=false;
                break;
            }
        }
    }


}