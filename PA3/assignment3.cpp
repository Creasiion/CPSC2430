#include <iostream>
#include "ShelterBST.h"

using namespace std;

void menu(int& userInput);
void testAll();

int main(){
  int menuOptions;
  string petName;
  int petNum;
  int petAge;
  ShelterBST tree;

  while(menuOptions != 0){
    menu(menuOptions);
    switch(menuOptions){
      case 1:
      cout << endl << "Please enter name of pet you are bringing into the shelter: ";
      cin >> petName;
      cout << endl << "Please input their age: ";
      cin >> petAge;
      tree.insertPet(petName, petAge);
      break;

      case 2:
      cout << endl << "Please enter name of pet you're searching for: ";
      cin >>petName;
      tree.searchPet(petName);
      break;

      case 3:
      cout << endl << "Displaying pets Preorder: ";
      tree.preorderDisplay();
      break;

      case 4:
      cout << endl << "Displaying pets Inorder: ";
      tree.inorderDisplay();      
      break;

      case 5:
      cout << endl << "Displaying pets Postorder: ";
      tree.postorderDisplay();      
      break;

      case 6:
      cout << endl << "Please input name of pet whose parent you want to find: ";
      cin >> petName;
      tree.searchPetParent(petName);
      break;

      case 7:
      cout << endl << "Please input name of pet whose predecessor you want to find: ";
      cin >> petName;
      tree.getPredecessor(petName);
      break;

      case 8:
      tree.getTotalPets();
      break;

      case 9:
      tree.getInternalPets();
      break;

      case 10:
      cout << endl << "Please input the level you want to know how many pets there are in: ";
      cin >> petNum;
      tree.getLevelPets(petNum);
      break;

      case 11:
      tree.getHeight();
      break;

      case 12:
      tree.balanced();
      break;

      case 13:
      cout << endl << "Please input the name of the pet you want to remove from the shelter: ";
      cin >> petName;
      tree.leavePet(petName);
      break;

      case 14:
      testAll();
      break;

      case 15:
      tree.destroyShelter();
      break;

      default:
      if(menuOptions != 0){
        cout << endl << "Invalid choice.";
      }
    }
  }
  tree.destroyShelter();
  return 0;
  
}
void menu(int& userInput){
  cout << endl << "Please select what you would like to do.";
  cout << endl << "1. Inserting a pet" << endl << "2. Searching for a pet" << endl
  << "3. Displaying pets PREORDER"<< endl << "4. Displaying pets INORDER" << endl << "5. Displaying pets POSTORDER"
  << endl << "6. Finding pet's parent" << endl << "7. Finding pet's predecessor"
  << endl << "8. Total number of pets" << endl << "9. Total number of INTERNAL pets" << endl
  << "10. Total number of pets at a given LEVEL" << endl << "11. Height of pet tree"
  << endl << "12. Check if tree is balanced" << endl << "13. Remove a pet from shelter"
  << endl << "14. Test all functions" << endl << "15. Remove ALL pets (destroy BST)"
  << endl << "0. End session." << endl;
  cin >> userInput;
}

void testAll(){
  ShelterBST experiment;
  cout << endl << "A. Inserting pets" << endl;
  experiment.insertPet("Imani", 11);
  experiment.insertPet("Uriah", 10);
  experiment.insertPet("Xuan", 13);
  experiment.insertPet("Riya", 11);
  experiment.insertPet("Albert", 15);
  experiment.insertPet("Jim", 21);
  experiment.insertPet("KillBill", 33);
  experiment.insertPet("AAAA", 4);
  experiment.insertPet("WEEEE",5);
  experiment.insertPet("OOOOH", 5);
  cout << endl << endl << "Testing for duplicate name. Input is Imani, program should reject.";
  experiment.insertPet("Imani", 13);
  cout << endl << endl << "B. Searching for a specific pet. Will be searching for Riya. Should find her." << endl;
  experiment.searchPet("Riya");
  cout << endl << endl <<"C1. Printing in PreOrder" << endl;
  experiment.preorderDisplay();
  cout << endl << endl<< "C2. Printing in PostOrder" << endl;
  experiment.postorderDisplay();
  cout << endl<< endl << "C3. Printing in InOrder" << endl;
  experiment.inorderDisplay();
  cout << endl<< endl << "D1. Finding parent of root (Imani). No parent should be found." << endl;
  experiment.searchPetParent("Imani");
  cout << endl<< endl << "D2. Printing parent of Uriah. Should be Imani.";
  experiment.searchPetParent("Uriah");
  cout << endl<< endl << "E1. Finding predecessor Imani.";
  experiment.getPredecessor("Imani");
  cout << endl<< endl << "E2. Finding no predecessor using node AAAA";
  experiment.getPredecessor("AAAA");
  cout << endl<< endl << "E3. Finding a predecessor using node OOOOH (leaf node)";
  experiment.getPredecessor("OOOOH");  
  cout << endl << endl << "F. Number of Nodes. Should be 10. ";
  experiment.getTotalPets();
  cout << endl << endl << "G. Number of Internal Nodes. Should be 7.";
  experiment.getInternalPets();
  cout << endl << endl << "H. Number of nodes at a given level: Level 1. (should give us 2)";
  experiment.getLevelPets(1);
  cout << endl << endl << "I. Get the height of tree. Should be 5.";
  experiment.getHeight();
  cout << endl << endl << "J. Checking the balance of tree. Result should be unbalanced";
  experiment.balanced();
  cout << endl << endl<< "K1. Deleting Node. Deleting Imani, the root.";
  experiment.leavePet("Imani");
  cout << endl;
  experiment.preorderDisplay();
  cout << endl << endl << "K2. Deleting Node. Deleting OOOOH, leaf node";
  experiment.leavePet("OOOOH");
  cout << endl;
  experiment.preorderDisplay();
  cout << endl << endl << "K3. Deleting Node. Deleting Jim, node with one kid";
  experiment.leavePet("Jim");
  cout << endl;
  experiment.preorderDisplay();  
  cout << endl << "L1. Destorying the entire tree.";
  experiment.destroyShelter();
  experiment.preorderDisplay();
  cout << endl << endl << "L2. Recreating the tree after deletion.";
  cout << endl;
  experiment.preorderDisplay();
  experiment.insertPet("Imani", 11);
  experiment.insertPet("Uriah", 10);
  experiment.insertPet("Xuan", 13);
  experiment.insertPet("Riya", 11);
  experiment.insertPet("Albert", 15);
  experiment.insertPet("Jim", 21);
  experiment.insertPet("Kill Bill", 33);
  experiment.insertPet("AAAA", 4);
  experiment.insertPet("WEEEE",5);
  experiment.insertPet("OOOOH", 5);
  cout << endl << endl << "The Recreated tree is displayed in preorder below." << endl;
  experiment.preorderDisplay();

}