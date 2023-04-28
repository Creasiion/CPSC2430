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
  
  TreeNode* insert(TreeNode* root, Pet* pet);
  TreeNode* search(TreeNode* root, string targetName);
  void inorder(TreeNode* root);
  void preorder(TreeNode* root);
  void postorder(TreeNode* root);
  TreeNode* parentSearch(TreeNode* root, string babyName);
  TreeNode* findPredecessor(TreeNode* node);
  int totalNode(TreeNode*root);
  int totalInternalNode(TreeNode* root);
  int totalLevelNodes(TreeNode* root, int level, int currlevel);
  int treeHeight(TreeNode*root);
  bool isBalanced(TreeNode* root);
  TreeNode* deletePet(TreeNode* root, string name);
  TreeNode* destroy(TreeNode* root);
  
public:
  ShelterBST();
  void insertPet(string name, int age);
  void searchPet(string name);
  void searchPetParent(string name);
  void inorderDisplay();
  void preorderDisplay();
  void postorderDisplay();
  void getPredecessor(string name);
  void getTotalPets();
  void getInternalPets();
  void getLevelPets(int desiredLvl);
  void getHeight();
  void balanced();
  void leavePet(string name);
  void destroyShelter();
};

#endif
