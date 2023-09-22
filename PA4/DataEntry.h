#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <iostream>
#include <string>
using namespace std;

class DataEntry{
private:
  string date;
  string country;
  int c_cases;
  int c_deaths;
  
public:
  DataEntry();
  DataEntry(string time, string name, int cases, int deaths);
  string getCountry();
  string getDate();
  int getCases();
  int getDeaths();
  void setCountry(string name);
  void setDate(string time);
  void setCase(int cases);
  void setDeaths(int deaths);
};

#endif
