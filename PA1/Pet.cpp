#include "Pet.h"
#include <iostream>

using namespace std;

Pet::Pet(string type, string name, int timeIn){
    animal = type;
    this->name = name;
    shelterTime = timeIn;
}

string Pet::getName() const{
    return name;
}

int Pet::getShelterTime() const{
    return shelterTime;
  }