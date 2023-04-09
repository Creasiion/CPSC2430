#include <iostream>
#include <queue>
#include "Pet.h"
using namespace std;


void menu(int& num);
void addCat(std::queue<Pet*>& cat, string name, int& tracker); //queue argument a pass-by reference
void addDog(std::queue<Pet*>& dog, string name, int& tracker);
void adoptCat(std::queue<Pet*>& cat); 
void adoptDog(std::queue<Pet*>& dog);
void adoptAny(std::queue<Pet*>& cat, std::queue<Pet*>& dog);

int main(){
  std::queue<Pet*> cat;
  std::queue<Pet*> dog;
  int petTracker = 0; //Tracker will be used to see which pet has been in shelter the longest. The smaller the number, the older the animal
  int userInput;
  string nameCat;
  string nameDog;
  Pet* dogGone = nullptr;
  Pet* catGone = nullptr;
  
  while(userInput != 6){
    menu(userInput);
    
    switch(userInput){
    case 1:
      addCat(cat, nameCat, petTracker);
      break;
      
    case 2:
      addDog(dog, nameDog, petTracker);
      break;
      
    case 3:
      adoptCat(cat);
      break;
      
    case 4:
      adoptDog(dog);
      break;
      
    case 5:
      adoptAny(cat,dog);
      break;
    }
  }
  //deleting animals still in queue
  while(!dog.empty()){
    dogGone = dog.front();
    dog.pop();
    delete dogGone;
  }
  while(!cat.empty()){
    catGone = cat.front();
    cat.pop();
    delete catGone;
  }
  return 0;
}

void menu(int& num){
  cout << endl << "Welcome to the animal shelter. What would you like to do?";
  cout << endl << "1. Add a CAT to the shelter";
  cout << endl << "2. Add a DOG to the shelter";
  cout << endl << "3. Adopt a CAT from the shelter";
  cout << endl << "4. Adopt a DOG from the shelter";
  cout << endl <<"5. Adopt any animal from the shelter";
  cout << endl << "6. Exit";
  cout << endl;
  cin >> num;
}

void addCat(std::queue<Pet*>& cat, string name, int& tracker){
cout << "Please enter the CAT's name:" << endl;
      cin >> name;
      tracker++;
      cat.push(new Pet("Cat", name, tracker));
}

void addDog(std::queue<Pet*>& dog, string name, int& tracker){
    cout << "Please enter the DOG's name:" << endl;
      cin >> name;
      tracker++;
      dog.push(new Pet("Dog", name, tracker));
}

void adoptCat(std::queue<Pet*>& cat){
  Pet* catTemp = nullptr;
  if(cat.empty()){
    cout << endl << "Sorry, no cats are available for adoption today";
  }else{
    catTemp = cat.front();
    cat.pop();
    cout << "Congrats on adopting a cat, their name is: " << catTemp->getName();
    delete catTemp;
  }
}
void adoptDog(std::queue<Pet*>& dog){
  Pet* dogTemp = nullptr;
  if(dog.empty()){
    cout << endl << "Sorry, no dogs are available for adoption today";
  }else{
    dogTemp = dog.front();
    dog.pop();
    cout << "Congrats on adopting a dog, their name is: " << dogTemp->getName();
    delete dogTemp;
  }
}
void adoptAny(std::queue<Pet*>& cat, std::queue<Pet*>& dog){
  if(cat.empty() && dog.empty()){
    cout << endl << "Sorry, no pets are available for adoption today";
  }else if(cat.empty()){ //If no cats, get the oldest dog
    adoptDog(dog);
  }else if(dog.empty()){ //If no dogs, get the oldest cat
    adoptCat(cat);
  }else{
    //Compare shelter time to see whose been there the longest. Smaller number, longer shelter time
    int catFront = cat.front()->getShelterTime();
    int dogFront = dog.front()->getShelterTime();
    if(catFront < dogFront){
      adoptCat(cat);
    }else if(dogFront < catFront){
      adoptDog(dog);
    }
  }
}
