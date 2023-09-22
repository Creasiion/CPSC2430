#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void merge(int a[], int p, int q, int r);
void mergeSort(int a[], int i, int j);
int partition(int a[], int i, int j);
void quickSort(int a[], int i, int j);
void heapify(int a[], int i, int j);
void heapSort(int a[], int i, int j);
void swap(int* a, int* b);
void printArray(int a[], int n);
void measureSort(void (*sortingFunction)(int*, int, int));

int main(){
  // function pointer
  void (*sortingFunction)(int*, int, int);
  cout << endl << "HEAP SORT" << endl;
  sortingFunction = &heapSort;
  measureSort(sortingFunction);
  cout << endl << "MERGE SORT" << endl;
  sortingFunction = &mergeSort;
  measureSort(sortingFunction);
  cout << endl << "QUICK SORT" << endl;
  sortingFunction = &quickSort;
  measureSort(sortingFunction);
  
  cout << endl << endl;
  return 0;
}
void merge(int a[], int p, int q, int r){
  int tempSize = r-p+1;
  int *temp= new int[tempSize]; //create a temp array of size r-p+1 to merge sorted elements
  int i = p, j = q+1;     //define two indices to start at p and q+1 respectively
  int index = 0;
  
  while(i <= q && j <= r){ // make sure not to go past q or r respectively
    // compare elements at each location and copy the smaller one
    if(a[i] <= a[j]){
      temp[index] = a[i];
      i++; // advance the index of the side your copied from
    }else{
      temp[index] = a[j];
      j++; // advance the index of the side your copied from
    }
    index++;
  }// repeat
  
  //incase of remaining elements
  while (i <= q) {
    temp[index] = a[i];
    i++;
    index++;
  }
  while (j <= r) {
    temp[index] = a[j];
    j++;
    index++;
  }
  
  index = 0;
  
  for(int i = 0; i < tempSize; i++){
    a[p+i] = temp[i];
  }
  delete [] temp;
}

void mergeSort(int a[], int i, int j){
  if (i < j) {
    int mid = (i+j)/2;
    mergeSort(a, i, mid);
    mergeSort(a, mid+1, j);
    merge(a,i,mid,j);
  }
}
int partition(int a[], int i, int j){
  int pivot = a[i];
  int m = i+1;
  for (int k = i+1; k <= j; k++) { //process unknown region
    if (a[k] < pivot) { // case 2: put a[k] to S1
      swap(a[m], a[k]);
      m++;
    } // case 1: put a[k] to S2. No else statement necessary
  }
  swap(a[i], a[m-1]);  // put the pivot at the right place
  return m-1; // return the pivot’s final position */
}
void quickSort(int a[], int i, int j) {
  if (i < j) {
    int pivotIndex = partition(a, i, j);
    quickSort(a, i, pivotIndex-1);
    quickSort(a, pivotIndex+1, j);
  }
}

void heapify(int a[], int i, int j){
  int largest = j;
  int left = 2*j+1;
  int right = 2*j+2;
  
  if(left < i && a[left] > a[largest]){
    largest = left;
  }
  if(right < i && a[right] > a[largest]){
    largest = right;
  }
  
  if(largest != j){
    swap(a[j], a[largest]);
    heapify(a, i, largest);
  }
}
void heapSort(int a[], int i, int j){
   int n = (j-i)+1;
  //Building the heap
  for(int k = (n/2) - 1; k >= 0; k--){
    heapify(a, n, k);
  }
  //Sorting
  for(int k = n - 1; k >= 0; k--){
    swap(a[i], a[i+k]);
    heapify(a, k, 0);
  }
}
void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int a[], int n){
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}


void measureSort(void (*sortingFunction)(int*, int, int)){
  int size[] = {10,100,1000,10000,100000};
  for(int i = 0; i < 5; i ++){
    //allocate memory for the array
    int* array = new int[size[i]];
    // fill in array with random numbers
    for(int j=0; j<size[i]; j++){
      array[j] = rand() % 100000;
    }
    // display size 10 random array
    if (size[i] == 10){
      cout << "Random array: " << endl;
      printArray(array, size[i]);
    }
    // Call the sorting function (make sure to
    // start with a new unsorted array each time)
    // and measure the execution time here
    auto start = high_resolution_clock::now();
    sortingFunction(array, 0, size[i] - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    // display size 10 sorted array
    if (size[i] == 10){
      cout << "Sorted array: " << endl;
      printArray(array, size[i]);
    }
    // display the time measurement with units
    cout << "Array size " << size[i] << " duration: ";
    cout << duration.count() << " ns." << endl;
  }
}
