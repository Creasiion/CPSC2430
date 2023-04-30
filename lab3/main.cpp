#include <iostream>
#include "ShelterBST.h"

using namespace std;

int main(){
  ShelterBST tree;
  
  cout << endl << "1. Searching an empty tree";
  tree.searchPet(1);
  
  cout << endl << endl << "2. Now inserting pets...";
  
  tree.insertPet("Zelda", 5);
  tree.insertPet("Uriah", 8);
  tree.insertPet("Fitz", 4);
  tree.insertPet("Riya", 6);
  tree.insertPet("Albert", 9);
  tree.insertPet("Xuan", 2);
  tree.insertPet("Crea", 7);
  tree.insertPet("Jimmy", 10);
  tree.insertPet("Crane", 3);
  tree.insertPet("Imani", 1);
  
  cout << endl << endl << "3. Inorder: " << endl;
  tree.inorderDisplay();
  cout << endl << "4. Postorder: " << endl;
  tree.postorderDisplay();
  cout << endl << "5. Preorder: " << endl;
  tree.preorderDisplay();
  
  cout << endl << "6. Finding a pet that isn't there";
  tree.searchPet(11);
  cout << endl << endl <<  "7. Finding a pet that is there";
  tree.searchPet(8);
  cout << endl;
  
  
  return 0;
}
