// Jose Fuentes
// Alex Melford
// Karina Hernandez
// Andy Wong
// Demo time: 5:05
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //for accumulator operations
using namespace std;

int main()
{
// an array of doubles
double arr[] = { 1.1, 2.2, 3.3, 2.2, 4.4 };

// Determine the array size
int size = sizeof(arr)/sizeof(arr[0]);

// initialize vector v1 to array arr
vector<double> v1(arr, arr + size);

//Display the contents of vector v1
cout << "Contents of vector: ";
for(double x: v1){
  cout << x << " ";
}
cout << endl;
// Sorting the Vector in Ascending order
sort(v1.begin(), v1.end());

// Display the content of vector v1 after sorting
cout << "Contents of vector after sorting: ";
for(double x: v1){
  cout << x << " ";
}
cout << endl;
// Reversing the Vector v1
reverse(v1.begin(), v1.end());
// Display the content of vector v1
cout << "Contents of vector 1 after reverse: ";
for(double x: v1){
  cout << x << " ";
}
cout << endl;

// Display the maximum element of vector v1
cout << "Maximum element: " << *max_element(v1.begin(), v1.end()) <<endl;
// Display the minimum element of vector v1
cout << "Minimum element: " << *min_element(v1.begin(), v1.end()) <<  endl;
// Display the accumulation of all elements in vector v1
// Starting the summation from 0
cout << "Accumulation of Vector elements: " << accumulate(v1.begin(), v1.end(), 0) << endl;

// Counts the occurrences of 2.2 from 1st to last element

int mycount = 0;
mycount = count(v1.begin(), v1.end(), 2.2);


// Display the counts
cout << "Count of occurences : " << mycount << endl;
// Delete second element of vector
v1.erase(next(v1.begin()));
// Display the v1 after erasing the element
cout << "Contents of vector 1 after deletion of second element: ";
for(double x: v1){
  cout << x << " ";
}
return 0;
}