#include <iostream>
#include <string>
#include <vector>
#include "DataEntry.h"
#include "CovidDB.h"
#include <fstream>
#include <sstream>
using namespace std;

void menu(int& userInput);
void readData(CovidDB& covidTrack, string csvFile);

int main(){
  CovidDB Tracker;
  string name, date;
  bool wasAdded;
  int caseNum, deathNum;
  int userInput;
  DataEntry* find = nullptr;
  
  string covFile = "WHO-COVID-data.csv";
  while(userInput != 0){
    menu(userInput);
    switch(userInput){
    case 1:
      readData(Tracker, covFile);
      cout << endl << endl << "Data from World Health Organization (WHO) has been used to create initial hash table.";
      break;
      
    case 2:
      cout << endl << "Please enter the name of your country: ";
      cin >> name;
      cout << endl << "Please enter the date of this entry In the format MM/DD/YY: ";
      cin >> date;
      cout << endl << "Please enter how many cases there are for the date: ";
      cin >> caseNum;
      cout << endl << "Please enter how many deaths there are for the date: ";
      cin >> deathNum;
      wasAdded = Tracker.add(new DataEntry(date, name, caseNum, deathNum));
      if(wasAdded){
        cout << endl << name << " was added successfully!";
      }
      break;
      
    case 3:
      cout << endl << "What country would you like to get? ";
      cin >> name;
      find = Tracker.get(name);
      if(find == nullptr){
        cout << " " << name << " is not a part of the data.";
      }else{
      cout << endl << find->getCountry() << "  " << find->getDate() << "  " << find->getCases() << "  " << find->getDeaths() << endl;
      }
      break;
      
            case 4:
              cout << endl << "What country would you like to delete? ";
              cin >> name;
              Tracker.remove(name);
              break;
              
    case 5:
      Tracker.display();
      break;
      
    default:
      if(userInput != 0){
        cout << endl << "Invalid choice.";
      }        
    }
  }
  
  return 0;
}

void menu(int& userInput){
  cout << endl << "Covid Tracker" << endl << "Please choose the operation you want:" << endl;
  cout << "1. Create the initial hash table" << endl << "2. Add a new data entry" << endl << "3. Get a data entry" 
       << endl << "4. Remove a data entry" << endl << "5. Display hash table" << endl << "0. Quit the system" << endl;
  cin >> userInput;
}
void readData(CovidDB& covidTrack, string csvFile){
  ifstream infile(csvFile);
  string date, country, cases, deaths, line;
  if(infile.fail()){
    cout << endl << "Error.";
    return;
  }
  
  
  getline(infile, line); //Skips first line
  
  
  while(getline(infile, line)){
    
    if(line == ""){
      continue;
    }
    
    stringstream ss(line);
    
    getline(ss, date, ',');
    getline(ss, country, ',');
    getline(ss, cases, ',');
    getline(ss, deaths, ',');
    
    int int_cases = stoi(cases);
    int int_deaths = stoi(deaths);
    
    covidTrack.add(new DataEntry(date,country, int_cases, int_deaths));
  }
  
  infile.close();
  
}
