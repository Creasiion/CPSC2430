#include <iostream>
#include <vector>

using namespace std;

int main()
{
// many ways to create a vector
// the example below only works with std=c++11
vector<int> v = {16,2,77,29};
// add an element at the end of the vector with push_back
v.push_back(31);
// one way to iterate through vector is using iterators
vector<int>::iterator it;
for(it=v.begin(); it!=v.end(); it++)
cout << ' ' << *it;
cout << endl;
// delete the last element in the vector
v.pop_back();
// size will be updated
cout << "This vector has " << v.size() << " elements." << endl;
// another way of iterating, use array [] notation
for(int i=0; i<(int)v.size(); i++)
cout << ' ' << v[i];
cout << endl;
// another way of creating a vector
vector<int> v2;
for(int i=0; i<10; i++)
v2.push_back(i);
// v2 should now have 0, 1, 2, ..., 9
}
