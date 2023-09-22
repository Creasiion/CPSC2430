//Imani Cage
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Pet{
  string name;
  int arrival;
  Pet(string newName, int dateCome){
    name = newName;
    arrival = dateCome;
  }
};

class PetHeap{
  
private:
  vector<Pet*> petHeap;
  void percolateUp(int index);
  void percolateDown(int index);
  void deleteMin();
  Pet* peekMin();
  
public:
  PetHeap(){
    petHeap = vector<Pet*>();
  }
  void insert(Pet* pet);
  Pet* adoptOldestPet();
  int numPets();
  void displayPets();
  void destroy();
};

void PetHeap::percolateUp(int index){
  if(index <= 0){
    //There's only ONE index in the vector, so nothing needs to move.
    return;
  }else{
    int parent = (index - 1)/2;
    if(petHeap[parent]->arrival > petHeap[index]->arrival){
      Pet* temp = petHeap[parent];
      petHeap[parent] = petHeap[index];
      petHeap[index] = temp;
      return percolateUp(parent); //return parent index since our node would be there now
    }else{
      return;
    }
  }
  
}
void PetHeap::percolateDown(int index){
  if(index <= 1 || petHeap.empty()){
    return;
  }
  int lChild = (index * 2) + 1;
  int rChild = (index * 2) + 2;
  int smallestInd = index;
  
  
  if((lChild < (int)petHeap.size()) &&(petHeap[lChild]->arrival < petHeap[smallestInd]->arrival)){
    smallestInd = lChild;
  }else if((rChild < (int)petHeap.size()) &&(petHeap[rChild]->arrival < petHeap[smallestInd]->arrival)){
    smallestInd = rChild;
  }
  
  if(smallestInd != index){
    Pet* temp = petHeap[index];
    petHeap[index] = petHeap[smallestInd];
    petHeap[smallestInd] = temp;
    percolateDown(smallestInd);
  }else{
    return;
  }
  
}
void PetHeap::deleteMin(){
  if(petHeap.empty()){
    return;
  }else{
    if(petHeap.size() > 1){
      Pet* temp = petHeap[0];
      petHeap[0] = petHeap[petHeap.size()-1]; //New root is equal to last element in vector
      petHeap.pop_back(); //Shrinks vector by one to account for deleted root
      delete temp;
      percolateDown(0);
    }else if (petHeap.size() == 1){
      Pet* temp = petHeap[0];
      petHeap.pop_back();
      delete temp;
    }
  }
}

Pet* PetHeap::peekMin(){
  //The oldest pet based off arrival would be the root, or the one with the smallest arrival date
  return petHeap[0];
}

void PetHeap::insert(Pet* pet){
  //uses percolateUp
  petHeap.push_back(pet);
  cout << endl << pet->name << " has been inserted!";
    percolateUp(petHeap.size()-1); 
    
}

Pet* PetHeap::adoptOldestPet(){
  if(petHeap.empty()){
    cout << endl << "Empty pet shelter.";
  }
  Pet* adoptedPet = peekMin();
  if(petHeap.size() >= 1){
    cout << endl << adoptedPet->name << " has been adopted!";
  }
  deleteMin();
  return adoptedPet;
}

int PetHeap::numPets(){
  return petHeap.size();
}

void PetHeap::displayPets(){
  if((int)petHeap.size() <= 0){
    cout << endl << "There are no pets in the shelter";
    return;
    }
  for(int i = 0; i < (int)petHeap.size(); i++){
    cout << petHeap[i]->name << " " << petHeap[i]->arrival;
    cout << endl;
  }
}

void PetHeap::destroy(){
  int index = (int)petHeap.size();
  for(int i = 0; i > index; i++){
    Pet* temp = petHeap[i];
    petHeap.pop_back();
        delete temp;
  }
  if(petHeap.empty()){
    cout << endl << "dealloacted right.";
  }
}

void menu(int& input);
void runTests();

int main(){
  PetHeap Shelter;
  int userInput;
  string petName;
  int arrivalDate;
  
  while(userInput != 6){
    menu(userInput);
    switch(userInput){
    case 1:
      {
        cout << endl << "Please put in the name of your pet: ";
        cin >> petName;
        cout << endl << "Input date of arrival: ";
        cin >> arrivalDate;
        Pet* newPet = new Pet(petName, arrivalDate);
        Shelter.insert(newPet);
      }
      break;
      
    case 2:
      {
        Shelter.adoptOldestPet();
      }
      break;
    case 3:
      {
        cout << endl << "We have " << Shelter.numPets() << " pets in our shelter." << endl;
      }
      break;
    case 4:
      {
        cout << endl << "Here are all of the pets in our shelter." << endl;
        Shelter.displayPets();
      }
      break;
    case 5:
      {
        runTests();
      }
      break;
      
    default:
      if(userInput != 6){
        cout << endl << "INVALID MENU OPTION.";
      }
    }
  }
  Shelter.destroy();
  
  return 0;
}
void menu(int& input){
  cout << endl << "Welcome to Lab 4 on Basic Heap Operations. What would you like to test?" << endl;
  cout << "1. Insert Pet" << endl << "2. Adopt Pet" << endl << "3. Number of Pets" 
       << endl  << "4. Display Pets" << endl << "5. Run Tests" << endl << "6. Exit" << endl;
  cin >> input;
}

void runTests(){
  PetHeap home;
  home.insert(new Pet("Imani", 12));
  home.insert(new Pet("ROOT", 1));
  home.insert(new Pet("2ROOT", 2));
  home.insert(new Pet("Riya", 11));
  home.insert(new Pet("Xuan", 14));
  home.insert(new Pet("Albeeeert", 3));
  home.insert(new Pet("Ray", 10));
  home.insert(new Pet("Uriah", 13));
  home.insert(new Pet("Ken", 5));
  home.insert(new Pet("Angela", 8));
  home.displayPets();
  cout << "adopting root... ";
  home.adoptOldestPet();
  cout << endl << "Pets now" << endl;
  home.displayPets();
  cout << endl << "Adopting multiple pets";
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  cout << endl << "Pets now" << endl;
  home.displayPets();
  cout << endl << "Adopting all pets until empty.";
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  home.adoptOldestPet();
  cout << endl << "Pets now" << endl;
  home.displayPets();
}
