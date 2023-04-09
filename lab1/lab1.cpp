//Imani Cage
#include <iostream>
using namespace std;

void starPrint(int num);
void binPrint();
int** buildPascal(int degree, int ** pascal);
int** inputPascal(int degree, int ** pascal);
void printPascal(int degree, int ** pascal);
int findCoefficient(int degree, int ** pascal, int index);

int main(){
  int numInput;
  int degree;
  int index;
  int ** pascal = nullptr;
  
  cout << endl << "Lab 1 Part 1: Please input a positive integer. ";
  cin >> numInput;
  cout << endl;
  starPrint(numInput);

  cout << endl << "Lab 1 Part 2: Please input a positive int for Pascal's triangle. ";
  cin >> degree;
  degree++; //accounts for index 0;
  while(index > degree - 1){ //Incase user tries to get out of bounds coefficient
  cout << endl << "Please input the index of the coefficient: ";
  cin >> index;
  }

  pascal = buildPascal(degree, pascal);
  inputPascal(degree, pascal);
  printPascal(degree, pascal);
  cout << "Your result is: " << findCoefficient(degree, pascal, index) << endl;

  //deleting the 2dArray
  for(int i = 0; i < degree + 1; i++){
    delete [] pascal[i];
  }
  delete [] pascal;
  return 0;
}


void starPrint(int num){
  for(int i = 0; i < num; i++){
    cout << "*" << endl;
  }

  cout << endl << endl;

  for(int i = 0; i <= num; i++){
    for(int j = 0; j <= i; j++){
      cout << "*";
    }
    cout << endl;
  }
}

 //Creation of 2d Array
 int** buildPascal(int degree, int ** pascal){
  pascal = new int*[degree + 1];
  for(int i = 0; i < degree + 1; i++){
    pascal[i] = new int[degree + 1];
  }
  return pascal;
 }
 //Inputing values inside 2d array
 int** inputPascal(int degree, int ** pascal){
  int row = 0;
  int colm = 0;
    while(row <= degree){
    if(colm == 0){
      pascal[row][colm] = 1;
    }
    if(colm == row){ //The end of that row
      pascal[row][colm] = 1;
      row++;
      colm = 0;
    }else{
      pascal[row][colm] = pascal[row - 1][colm - 1] + pascal[row - 1][colm];
      colm++;
        }
  }
  return pascal;
 }
 //Printing the triangle
void printPascal(int degree, int ** pascal){
  int row = degree;
     cout << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
          if(pascal[i][j] == 0){
            continue;
          }else{
            cout <<  pascal[i][j] << " ";
          }
        }
        cout << endl;
    }
}
int findCoefficient(int degree, int ** pascal, int index){
  return pascal[degree - 1][index]; //degree - 1 taking into account the increment of degree from line 25
}