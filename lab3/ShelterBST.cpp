#include <iostream>
#include <string>
#include "ShelterBST.h"

using namespace std;

void ShelterBST::insertPet(string name, int age){
  root = insert(root, new Pet(name, age));
}
void ShelterBST::searchPet(int age){
  TreeNode* result = search(root, age);
  if(!result){
    cout << endl << "There is no pet of that age.";
  }else{
    cout << endl << result->pet->name << " has been found with desired age!";
  }
}
void ShelterBST::inorderDisplay(){
  inorder(root);
}
void ShelterBST::preorderDisplay(){
  preorder(root);
}
void ShelterBST::postorderDisplay(){
  postorder(root);
}
