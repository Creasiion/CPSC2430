#ifndef SHELTERBST_H
#define SHELTERBST_H

#include <iostream>
#include <string>
using namespace std;

class ShelterBST{
private:
  struct Pet{
    string name;
    int age;
    Pet(string petName, int petAge){
      name = petName;
      age = petAge;
    };
  };
  
  struct TreeNode{
    Pet* pet;
    TreeNode* left;
    TreeNode* right;
};
  
  TreeNode* root;
  
  TreeNode* insert(TreeNode* root, Pet* pet){
    if(!root){
      //If there's no root, create a new node and set it as the root - similar to inserting in a linked list
      TreeNode* newNode = new TreeNode();
      newNode->pet = pet;
      newNode->left = nullptr;
      newNode->right = nullptr;
      root = newNode;
      return newNode;
    }else if(pet->age > root->pet->age ){ //If value is greater than root, value is on the rightside of the root
      root->right = insert(root->right, pet);
    } else if(pet->age < root->pet->age){ //Otherwise is on the left
      root->left = insert(root->left, pet);
    }
    return root;
  }
  TreeNode* search(TreeNode* root, int age){
    if(!root){
      cout << endl << "No tree to search";
      return nullptr;
    }else if(root->pet->age == age){
      return root;
    }else if(age > root->pet->age){
      return search(root->right, age);
    }else if(age < root->pet->age){
      return search(root->left, age);
    }
    return nullptr;
  }
  
  void inorder(TreeNode* root){
    if(!root){
      return;
    }else{
      inorder(root->left);
      cout << root->pet->name << " " << root->pet->age << endl;
      inorder(root->right);
    }
  }
  void preorder(TreeNode* root){
    if(!root){
      return;
    }else{
      cout << root->pet->name << " " << root->pet->age << endl;
      preorder(root->left);
      preorder(root->right);
    }
  }
  void postorder(TreeNode* root){
    if(!root){
      return;
    }else{
      postorder(root->left);
      postorder(root->right);
      cout << root->pet->name << " " << root->pet->age << endl;
    }
  }
  
public:
  ShelterBST(){
    root = nullptr;
  }
  void insertPet(string name, int age);
  void searchPet(int age);
  void inorderDisplay();
  void preorderDisplay();
  void postorderDisplay();
};

#endif
