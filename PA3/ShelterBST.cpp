#include <iostream>
#include <string>
#include "ShelterBST.h"

using namespace std;

ShelterBST::ShelterBST(){
    root = nullptr;
  }

//PRIVATE FUNCTIONS
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet){
    if(!root){
      //If there's no root, create a new node and set it as the root - similar to inserting in a linked list
      TreeNode* newNode = new TreeNode();
      newNode->pet = pet;
      newNode->left = nullptr;
      newNode->right = nullptr;
      cout << endl << pet->name << " has been added to the shelter.";
      return newNode;
    }else if(pet->name == root->pet->name){
      cout << endl << "Sorry! This name already exists for a pet!";
      return root;
    }else if(pet->name > root->pet->name){ //If value is greater than root, value is on the rightside of the root
      root->right = insert(root->right, pet);
    } else if(pet->name < root->pet->name){ //Otherwise is on the left
      root->left = insert(root->left, pet);
    }
    return root;
  }

ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, string targetName){
    if(!root){
      cout << endl << "No tree to search";
      return nullptr;
    }else if(root->pet->name == targetName){
      return root;
    }else if(targetName > root->pet->name){
      return search(root->right, targetName);
    }else{
      return search(root->left, targetName);
    }
  }

void ShelterBST::inorder(TreeNode* root){
    if(!root){
      return;
    }else{
      inorder(root->left);
      cout << root->pet->name << " " << root->pet->age << endl;
      inorder(root->right);
    }
  }

void ShelterBST::preorder(TreeNode* root){
    if(!root){
      return;
    }else{
      cout << root->pet->name << " " << root->pet->age << endl;
      preorder(root->left);
      preorder(root->right);
    }
  }

  void ShelterBST::postorder(TreeNode* root){
    if(!root){
      return;
    }else{
      postorder(root->left);
      postorder(root->right);
      cout << root->pet->name << " " << root->pet->age << endl;
    }
  }

  ShelterBST::TreeNode* ShelterBST::parentSearch(TreeNode* root, string babyName){
    if(!root){
      //If we search the tree and no parent was found
      return nullptr;
    }else if((root->left && root->left->pet->name == babyName) || (root->right && root->right->pet->name == babyName)){
      //If either of the root's children is the target, then the root is the parent
      return root;
    }else if(babyName < root->pet->name){
      return parentSearch(root->left, babyName);
    }else{
    return parentSearch(root->right, babyName);
      }
    }

    ShelterBST::TreeNode* ShelterBST::findPredecessor(TreeNode* node){
    //Only for a given node with TWO CHILDREN
    if(!root){
      return nullptr;
    }
    if(!node->left){
      //EXTRA: Edge case for no left node. 
      //If the root does not have a left, then it's predecessor COULD be their parent.
      //Only if child is on the rightside of the parent.
      //DOES NOT APPLY FOR ROOT 
      TreeNode* parent = parentSearch(root, node->pet->name);
      if(parent->right == node){
      return parent;
      }else{
      return nullptr;
    }
    }
 node = node->left;
 while(node->right){
  node = node->left;
 }
 return node;
}

  int ShelterBST::totalNode(TreeNode*root){
    if(!root){
      return 0;
    }else{
      return 1 + totalNode(root->left) + totalNode(root->right);
    }
  }

  int ShelterBST::totalInternalNode(TreeNode* root){
  if(!root){
    return 0;
  }else if(root->left == nullptr && root->right == nullptr){
    //If the node does not have a kid, that means it's a lead node. Do not add it
    return 0;
  }else{
    return 1 + totalInternalNode(root->left) + totalInternalNode(root->right);
  }
}

int ShelterBST::totalLevelNodes(TreeNode* root, int level, int currlevel = 0){
  if(!root){
    return 0;
  }else if(currlevel == level){
    return 1;
  }else{
    return totalLevelNodes(root->left, level, currlevel + 1) + totalLevelNodes(root->right, level, currlevel + 1);
  }
}

int ShelterBST::treeHeight(TreeNode*root){
  if(!root){
    return -1;
  }else{
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
  }
}

bool ShelterBST::isBalanced(TreeNode* root){
  if(!root){
    cout << endl << "No tree.";
    return true;
  }else{
  int lHeight = treeHeight(root->left);
  int rHeight = treeHeight(root->right);
  if((abs(lHeight - rHeight) <= 1) && (isBalanced(root->left)) && (isBalanced(root->right))){
    return true;
  }else{
    return false;
  }
  }
}

ShelterBST::TreeNode* ShelterBST::deletePet(TreeNode* root, string name){
  if(!root){
    return nullptr;
  }
  if(name < root->pet->name){
    root->left = deletePet(root->left, name);
  }else if(name > root->pet->name){
    root->right = deletePet(root->right, name);
  }else if(root->pet->name == name){
    if(!root->left && !root->right){ //Node has no children
      delete root->pet;
      delete root;
      return nullptr;
    }else if(!root->left && root->right){ //Node only has right child
      TreeNode* temp = root->right;
      delete root->pet;
      delete root;
      return temp;
    }else if(!root->right && root->left){//Node only has left child
      TreeNode* temp = root->left;
      delete root->pet;
      delete root;
      return temp;
    }else{//Node has 2 children
      TreeNode* temp = findPredecessor(root);
      root->pet->name = temp->pet->name;
      root->pet->age = temp->pet->age;
      root->left = deletePet(root->left, temp->pet->name);
    }
  }
  return root;
}


  ShelterBST::TreeNode* ShelterBST::destroy(TreeNode* root){
    if (!root) {
        return nullptr;
    }
    destroy(root->left);
    destroy(root->right);

    delete root;
    return nullptr;
}
//PUBLIC FUNCTIONS
void ShelterBST::insertPet(string name, int age){
  root = insert(root, new Pet(name, age));
}
void ShelterBST::searchPet(string name){
  TreeNode* result = search(root, name);
  if(!result){
    cout << endl << "There is no pet of that name.";
  }else{
    cout << endl << result->pet->name << " has been found!";
  }
}
void ShelterBST::searchPetParent(string name){
  TreeNode* parent = parentSearch(root, name);
  if(!parent){
    cout << endl << "Sorry, no parent has been found.";
  }else{
    cout << endl << parent->pet->name << " is the parent of " << name << "! Age: " << parent->pet->age;
  }
}

void ShelterBST::getPredecessor(string name){
  TreeNode* findFor = search(root, name);
  TreeNode* pred = findPredecessor(findFor);
  if(pred){
    cout << endl << "The predecessor for " << name << " is " << pred->pet->name << "!";
  }else{
    cout << endl << "The predecessor for " << name << " does not exist.";
  }
}

void ShelterBST::getTotalPets(){
  int total = totalNode(root);
  cout << endl << "The total amount of pets in the shelter are: " << total;
}

void ShelterBST::getInternalPets(){
   int inTotal = totalInternalNode(root);
   cout << endl << "The total amount of internal pets in the shelter are: " << inTotal;
}

void ShelterBST::getLevelPets(int desiredLvl){
  int lvlTotal = totalLevelNodes(root, desiredLvl);
   cout << endl << "The total amount of pets on level " << desiredLvl << " in the shelter are: " << lvlTotal;
}

void ShelterBST::getHeight(){
  cout << endl << "The height of this pet shelter tree is: " << treeHeight(root);
}

void ShelterBST::balanced(){
  if(isBalanced(root)){
    cout << endl << "The pet shelter is a balanced BST!";
  }else{
    cout << endl << "The pet shelter is NOT a balanced BST.";
  }
}

void ShelterBST::leavePet(string name){
  cout << endl << "Deleting " << name << "...";
  TreeNode* deleted = deletePet(root, name);
  if(deleted){
    cout << name << " had been deleted!";
  }else{
    cout << endl << "unsucessful";
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

void ShelterBST::destroyShelter(){
  cout << endl << "Destroying animal BST...";
  root = destroy(root);
  if(!root){
    cout << endl << "Successfully destroyed tree!";
  }else{
    cout << endl << "Unsuccessful.";
  }
}
