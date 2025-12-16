//***********************************************************
// Name: Yoshi Kobayashi
// Title: CSE100 Instructor
// Author Info: Faculty ASU
// Description: Assignment8 Template
// Date:
//**********************************************************
#include "Guest.h"
#include <string>
#include <iostream>
using namespace std;

Guest::Guest(){
  priority = -1;
  name = "";
}
Guest::Guest(string n, int m){
  priority = m;
  name = n;
}
int Guest::getPriority(){ return priority;}
void Guest::setPriority(int x){priority = x;}
string Guest::getName(){return name;}
void Guest::setName(string x){name = x;}
string Guest::getInfo(){
  if(getPriority()==-1) return "*   ";
  else {
    string s = "";
    s += getName().at(0);  // get the initial letter
    s += "-";
    s += to_string(getPriority()) + " "; // get the priority as a string
    return s;
  }
}
bool Guest::equals(Guest other){
  if(other.name == name && other.priority == priority) return true;
  return false;
}