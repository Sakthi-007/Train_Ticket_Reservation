//
// Created by SakthiVignesh on 16-07-2025.
//

#include "Train.h"
int Train::PNR=1000;

Train::Train(string name,string number): trainName(name), trainNumber(number) {
}

void Train::addCoach(coach *newCoach) {

    coaches.push_back(newCoach);
}

void Train::getDetailes() {

    cout<<"Train Name:"<<trainName<<endl;
    cout<<"Train Number:"<<trainNumber<<endl;
    cout<<"Coaches in the train:"<<coaches.size()<<endl;
    int k=1;
    for (auto i:coaches) {
        cout<<"Coach "<<k++<<endl;
        i->getCabins();
    }
}


void Train::bookTicket(user *person) {
    // Booking logic here
    if (person->getAge()<5) {
        cout<<"\nNo ticket Needed for children\n";
    }

    vector<user*>passengers;
    passengers.push_back(person);
    for (auto &group:person->group) {
        if (group->getAge()<5) {
            cout<<"\nNo ticket Needed for children\n";
            continue;
        }
        passengers.push_back(group);
    }

    int n=passengers.size();
    bool allbooked=true;
    int totalbooked=0;
    vector<user*>remaining;;
    vector<tuple<user*,cabin*,int>>allocations;

    for (auto *passenger:passengers) {
        bool booked=false;
        string seatType=getSeatType(passenger->getAge(), passenger->getPreference());

        for (auto *coach:coaches) {
            for (auto *cabin:coach->getCabinsList()) {
                auto &seat=cabin->seats;
                for (int i=0;i<seat.size();i++) {
                    if (!seat[i].second && seat[i].first.find(seatType)!=string::npos){
                        allocations.push_back({passenger,cabin,i});
                        cabin->seats[i].second=true;
                        booked=true;
                        break;

                    }
                }
                if (booked)break;
            }if (booked)break;
        }
        if (!booked) {
            remaining.push_back(passenger);
            allbooked=false;
        }
        else{totalbooked++;}
    }

    if (!allbooked) {
        for (auto *passenger:remaining) {
            bool booked=false;
            for (auto *coach:coaches) {
                for (auto *cabin:coach->getCabinsList()) {
                        auto&seat=cabin->seats;
                    for (int i=0;i<seat.size();i++) {
                        if (!seat[i].second && seat[i].first!="SIDELRAC") {
                            allocations.push_back({passenger,cabin,i});
                            cabin->seats[i].second=true;
                            booked=true;
                            break;
                        }
                    }if (booked)break;
                }if (booked)break;
            }if (!booked) {
                for (const auto&[_,cabin,idx]:allocations) {
                    cabin->seats[idx].second=false;
                }
                cout<<"\nNo seats available for "<<passenger->getName()<<" with preference "<<passenger->getPreference()<<endl;
                cout<<"\nBooking Failed!"<<endl;
                allocations.clear();
                return;
            }
            else {
                totalbooked++;
            }

        }
    }

    if (totalbooked==n) {
        cout<<"\nBooking Successfull!"<<endl;
        cout<<"Your PNR is: "<<++PNR<<endl;
        for (const auto&[user,cabin,seatIdx]:allocations)
        {
            bookings[PNR].push_back(user);
            }
    }
    mainallocations[PNR].push_back(allocations);
}


string Train::getSeatType(int age,int preference) {
    if (age>60)return "LOWER";
    switch (preference) {
        case 1: return "UPPER";
        case 2: return "LOWER";
        case 3: return "MIDDLE";
        case 4: return "SIDEU";
        case 5: return "SIDEL";
        default: return "INVALID PREFERENCE";
    }
}


void Train::displayBookings(int pnr) {
    if (bookings.find(pnr)==bookings.end()) {
        cout<<"\nNo bookings found for PNR: "<<pnr<<endl;
        return;
    }

    cout<<"\nBookings for PNR: "<<pnr<<endl;
    for (auto user:bookings[pnr]) {
        cout<<"Name: "<<user->getName()<<", Age: "<<user->getAge()<<", Preference: "<<user->getPreference()<<endl;
    }
}

void Train::cancelTicket(int bookingID) {
    for (const auto&[user,cabin,idx]:mainallocations[bookingID][0]) {
        cabin->seats[idx].second=false;

    }
    bookings.erase(bookingID);
    cout<<"\nBooking with ID "<<bookingID<<" has been cancelled successfully."<<endl;
}

