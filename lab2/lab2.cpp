#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int** iterativePascal(int degree, int ** pascal);
int iterativeCoeff(int degree, int ** pascal, int index);
void printIterative(int degree, int ** pascal);
int recursiveBico(int degree, int index);
void printRecursive(int degree);

int main(){
  int degree;
  int index;
  int ** pascal = nullptr;
  
  cout << "Please input the degree of the binomial: ";
  cin >> degree;
  degree++; //Previous lab increased degree by 1 for the 2D array
  cout << endl << "Please input the index of the coefficient: ";
  cin >> index;
  
  cout << endl << "Lab 1, iterative pascal triangle:";
  pascal = iterativePascal(degree, pascal);
  printIterative(degree, pascal);
  cout << "Your result is: " << iterativeCoeff(degree, pascal, index) << endl;
  
  cout << endl << "Lab  2, recursive pascal triangle:" << endl;
  printRecursive(degree);
  cout << "Your result is: " << recursiveBico(degree - 1, index) << endl;
  
  //deleting the 2D Array used in iterativePascal
  for(int i = 0; i < degree + 1; i++){
    delete [] pascal[i];
  }
  delete [] pascal;
  
  return 0;
  
}
int** iterativePascal(int degree, int ** pascal){
  int row = 0;
  int colm = 0;
  pascal = new int*[degree + 1];
  for(int i = 0; i < degree + 1; i++){
    pascal[i] = new int[degree + 1];
  }
  while(row <= degree){
    if(colm == 0){
      pascal[row][colm] = 1;
    }
    if(colm == row){ 
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
int iterativeCoeff(int degree, int ** pascal, int index){
  return pascal[degree - 1][index];
}
void printIterative(int degree, int ** pascal){
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

int recursiveBico(int degree, int index){
  if(index == 0 || index == degree){
    return 1;
  }else{
    return recursiveBico(degree -1, index - 1) + recursiveBico(degree - 1, index);
  }
}
void printRecursive(int degree){
  for(int i = 0; i < degree;i++){
    for(int j = 0; j <= i; j++){
      cout << recursiveBico(i, j) << " ";
    }
    cout << endl;
  }
}
