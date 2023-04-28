//Imani Cage
//assignment2.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void menu(int& input);
int mysterySequence(int n);
int tennisBalls(int n);
string decToBase2(int n);
bool isDivisibleBy7(int n);
double ramanujan(double depth, double eqn);
void testRun();

int main(){
  int userInput;
  int mysteryNum;
  int height;
  int convert;
  int numDiv;
  double depth;
  double ramEqn = 0.0;
  
  while(userInput != 7){
    menu(userInput);
    switch(userInput){
    case 1: //Mystery Sequence
      cout << endl << "Mystery Sequence. Please enter n to compute the nth number in sequence:" << endl;
      cin >> mysteryNum;
      cout << endl << "The " << mysteryNum << " number in mystery sequence is " << mysterySequence(mysteryNum);
      break;
      
    case 2: //Spherical Balls
      cout << endl << "Tennis Balls. Please enter the height of the pyramid:" << endl;
      cin >> height;
      cout << endl << "A pyramid with " << height << " levels holds " << tennisBalls(height)<< " balls.";
      break;
    case 3: //Interger to Binary
      cout << endl << "Interger to Binary. Please enter the number to convert:" << endl;
      cin >> convert;
      cout << endl << convert << " in binary is " << decToBase2(convert);
      break;
    case 4: // Divisible by 7
      cout << endl << "Divisible by 7. Please enter the number to see if it's divisble by 7:" << endl;
      cin >> numDiv;
      if(isDivisibleBy7(numDiv)){
        cout << endl << numDiv << " is divisible by 7";
      }else{
        cout << endl << numDiv << " is NOT divisible by 7";
      }
      break;
    case 5: //Ramanujan
      cout << endl << "Ramanujan. Enter integer depth: ";
      cin >> depth;
      cout << endl << "Result at depth " << depth << ": " << ramanujan(depth, ramEqn);
      cout << endl << "Result at infinite depth: 4"; 
      break;
    case 6://Run Tests
      testRun();
      break;
    default:
      if(userInput != 7){
        cout << endl << "Invalid choice.";
      }
    }
  }
  return 0;
}

void menu(int& input){
  cout << endl << " Welcome to the recursion assignment. What would you like to test?";
  cout << endl << "1. mysterySequence" << endl << "2. tennisBalls" << endl << "3. decToBase2"
       << endl << "4. isDivisibleBy7" << endl << "5. ramanujan" << endl << "6. run tests" << endl << "7. Exit" << endl;
  cin >> input;
}

int mysterySequence(int n){
  if(n <= 0){ //Base case 1 since the Mystery Sequence starts off as 2
    return 2;
  }else if (n == 1){ //Second base case since 3 is the only part that does not match the pattern
    return 3;
  }else{
    return mysterySequence(n-1) * mysterySequence(n - 2);
  }
}
int tennisBalls(int n){
  //The sequence of the pyramrid is the height squared for the current layer 
  //i.e. layer 3 has 9 balls
  //And added with the previous layers to get the full count.
  if(n == 0){ //There are 0 Tennis balls
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    return (n*n) + tennisBalls(n - 1);
  }
}
string decToBase2(int n){
  if(n == 0 || n == 1){
    return to_string(n%2);
  }else{
    return (decToBase2(n/2) + to_string(n%2));
  }
}
bool isDivisibleBy7(int n){
  int lastDigit = n%10;
  n -= 2*lastDigit;
  if(n >= 100){ //If our integer is less than 2 digits, it'll always be less than 100
    return isDivisibleBy7(n);
  }else{
    return !(n%7); //! used in order to return true if divisible by 7
  }
}

double ramanujan(double depth, double eqn = 0.0){
  if(depth < 0.0){
    return sqrt(6.0 + eqn);
  }else{
    eqn = (depth + 1.0) * sqrt(depth + 6.0 + eqn);
    return ramanujan(depth - 1.0, eqn);
  }
}
void testRun(){
  cout << endl << "1. mysterySequence with n = 0, 1, 4, 7";
  cout << endl << mysterySequence(0) << " " << mysterySequence(1) << " " << mysterySequence(4) << " " << mysterySequence(7) << endl;;
  cout << endl << "2. tennisBalls with height = 0, 1, 3, 10";
  cout << endl << tennisBalls(0) << " " << tennisBalls(1) << " " << tennisBalls(3) << " " << tennisBalls(10) << endl;
  cout << endl << "3. decToBase2 with input = 0, 1, 13, 32, 321";
  cout << endl << decToBase2(0) << " " << decToBase2(1) << " " << decToBase2(13) << " " << decToBase2(32) << " " << decToBase2(321) << endl;
  cout << endl << "4. isDivisibleBy7 with input = 1, 7, 31, 1073, 1729";
  if(isDivisibleBy7(1)){
    cout << endl << "1 is disvisible by 7";
  }else{
    cout << endl << "1 is NOT divisible by 7";
  }
  if(isDivisibleBy7(7)){
    cout << endl << "7 is disvisible by 7";
  }else{
    cout << endl << "7 is NOT divisible by 7";
  }
  if(isDivisibleBy7(31)){
    cout << endl << "31 is disvisible by 7";
  }else{
    cout << endl << "31 is NOT divisible by 7";
  }
  if(isDivisibleBy7(1073)){
    cout << endl << "1073 is disvisible by 7";
  }else{
    cout << endl << "1073 is NOT divisible by 7";
  }
  if(isDivisibleBy7(1729)){
    cout << endl << "1729 is disvisible by 7";
  }else{
    cout << endl << "1729 is NOT divisible by 7";
  }
  cout << endl << endl << "5. Ramanujan with depth = 1, 3, 10";
  cout << endl << ramanujan(1.0, 0.0) << " " << ramanujan(3.0, 0.0) << " " << ramanujan(10.0, 0.0);
}
