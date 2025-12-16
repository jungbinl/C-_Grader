//***********************************************************
// Name: Yoshi Kobayashi
// Title: CSE100 Instructor
// Author Info: Faculty ASU
// Description: Assignment8 Template
// Date:
//**********************************************************
#ifndef GUEST_H
#define GUEST_H

#include <iostream>
using namespace std;

class Guest{
  private:
    string name;
    int priority;
  public:
    Guest();
    Guest(string, int);
    string getName();
    int getPriority();
    void setName(string);
    void setPriority(int);
    string getInfo();
    bool equals(Guest);
};

#endif