#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "CovidDB.h"
using namespace std;

int CovidDB::hash(string country){
  //Hash function will give us index placement for our desired country
  int sum = 0;
  for(int i = 0; i < (int)country.length(); i++){
    sum += ((i+1)*country.at(i));
  }
  return sum % tableSize;
}

CovidDB::CovidDB(){
  tableSize = 17; //our given initial hash table size
  loadFactor = 1;
  hashTable = vector<vector<DataEntry*>>(tableSize);
}

void CovidDB::display(){
  cout << endl;
  for(int i = 0; i < tableSize; i++){
    cout << i;
    for(int j = 0; j < (int)hashTable[i].size(); j++){
      cout << "-> " << hashTable[i][j]->getCountry() << ", " << hashTable[i][j]->getDate() << ", " <<  hashTable[i][j]->getCases() << ", " << hashTable[i][j]->getDeaths();
      cout << endl;
    }
    cout << endl;
  }
}

bool CovidDB::add(DataEntry* entry){
  int index = hash(entry->getCountry());
  //Search the entire index entry would be in
  for(int i = 0; i < (int)hashTable[index].size(); i++){
    //Compare all entries with current one to see if duplicate.
    if(hashTable[index][i]->getCountry() == entry->getCountry()){
      if(recentDate(entry->getDate(), hashTable[index][i]->getDate())){
        //If our input entry for a country is more up to date
        int newDeaths = hashTable[index][i]->getDeaths() + entry->getDeaths();
        int newCases = hashTable[index][i]->getCases() + entry->getCases();
        hashTable[index][i] = entry;
        hashTable[index][i]->setDeaths(newDeaths);
        hashTable[index][i]->setCase(newCases);
        return true; //Entry is added, but total number of entries is not incremented
      }else{
        return false; // New entry rejected if not as up to date as prev.
      }
    } //end of outer if statement
  } // End for for loop - If duplicate is not found, then a new entry will be addded
  hashTable[index].push_back(entry);
  return true;
}

void CovidDB::remove(string country){
  int index = hash(country);
  for(int i = 0; i < (int)hashTable[index].size(); i++){
    if(hashTable[index][i]->getCountry() == country){
      DataEntry* temp = hashTable[index][i]; //hold value address in pointer temp
      hashTable[index].erase(hashTable[index].begin() + i);
      delete temp; //delete temp since values are pointers
      cout << endl << country << " is deleted!";
      return;
    }
  }
  cout << endl << country << " is not in the table.";
}

DataEntry* CovidDB::get(string country){
  int index = hash(country); //Find index target would be in
  DataEntry* target = nullptr;
  //Search the entire index country would be in until found
  for(int i = 0; i < (int)hashTable[index].size(); i++){
    if(hashTable[index][i]->getCountry() == country){
      target = hashTable[index][i];
      cout << endl << "Target has been found.";
      return target;
    }
  }
  cout << endl << country << " has not been found.";
  return target;
}
bool CovidDB::recentDate(string currDATE, string prevDATE){
  //Comparing dates of recent data entry with it's previous one
  //Will return true if recent data entry is more up to date, false otherwise
  string yearCurr, yearPrev, monthCurr, monthPrev, dayCurr, dayPrev;
  stringstream ss1(currDATE);
  stringstream ss2(prevDATE);
  getline(ss1, monthCurr, '/');
  getline(ss1, dayCurr, '/');
  getline(ss1, yearCurr, '/');
  getline(ss2, monthPrev, '/');
  getline(ss2, dayPrev, '/');
  getline(ss2, yearPrev, '/');

  
  if(yearCurr != yearPrev){
    return stoi(yearCurr) > stoi(yearPrev);
  }else if(monthCurr != monthPrev){
    return stoi(monthCurr) > stoi(monthPrev);
  }else{ //If dates have the same year, then compare the month
    return stoi(dayCurr) > stoi(dayPrev);
  }
return true; //If dates have the same year, month, and day, then update with current given entry
}
CovidDB::~CovidDB(){
  for(int i = 0; i < tableSize; i++){
    for(int j = 0; j < (int)hashTable[i].size(); j++){
      DataEntry* temp = hashTable[i][j]; 
      hashTable[i].erase(hashTable[i].begin() + j);
      delete temp; 
    }
    hashTable[i].clear();
  }
  hashTable.clear();
  if(hashTable.empty()){
    cout << endl << "Table has been deleted.";
  }
}

