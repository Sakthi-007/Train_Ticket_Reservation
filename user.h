//
// Created by SakthiVignesh on 16-07-2025.
//

#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
using namespace std;

class user {
private:
    string name;
    int age;
    int preference;
    int members;
public:
    vector<user*>group;
    void setDetails(string name,int age,int preference,int members);
    string getName() const { return name; }
    int getAge() const { return age; }
    int getPreference() const { return preference; }
};



#endif //USER_H
