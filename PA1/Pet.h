#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

class Pet{
private:
  string animal;
  string name;
  int shelterTime;
  
public:
  Pet(string type, string name, int timeIn);
  string getName() const;
  int getShelterTime() const;
};

#endif