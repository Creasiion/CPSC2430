#include <iostream>
#include <string>
#include "DataEntry.h"
using namespace std;

DataEntry::DataEntry(){
  date = "";
  country = "";
  c_cases = 0;
  c_deaths = 0;
}
DataEntry::DataEntry(string time, string name, int cases, int deaths){
  date = time;
  country = name;
  c_cases = cases;
  c_deaths = deaths;
}
string DataEntry::getCountry(){
  return country;
}
string DataEntry::getDate(){
  return date;
}
int DataEntry::getCases(){
  return c_cases;
}
int DataEntry::getDeaths(){
  return c_deaths;
}
void DataEntry::setCountry(string name){
  country = name;
}
void DataEntry::setDate(string time){
  date = time;
}
void DataEntry::setCase(int cases){
  c_cases = cases;
}
void DataEntry::setDeaths(int deaths){
  c_deaths = deaths;
}
