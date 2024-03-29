#ifndef COVIDDB_H
#define COVIDDB_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "DataEntry.h"
using namespace std;

class CovidDB{
private:
  int tableSize;
  int numEntries;
  int loadFactor;
  vector<vector<DataEntry*>> hashTable;
  int hash(string country);
  
public:
  CovidDB(); //constructor to set up hashtable vector
  void display();
  bool add(DataEntry* entry);
  //adds a DataEntry into your hash table; if it already exists, then update it
  //returns true if record is added, false if record is rejected (date < than current date)
  DataEntry* get(string country);
  //return data for country (null if n/a)
  void remove(string country);
  //remove data for country
  bool recentDate(string currDATE, string prevDATE);
  ~CovidDB();
};

#endif
