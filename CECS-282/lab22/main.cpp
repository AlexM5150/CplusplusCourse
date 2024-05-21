//Purnima Jain
//Alex Melford
//Aiden Hock
//Demo Time: 5:14
#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

int safeAdd(int x, int y){
  cout << "Adding " << x <<" and "<< y << " \n" <<endl;
  int sum = x + y;
  if(x > 0 && y > 0 && sum < 0) 
        throw "Adding will cause overflow"; 
  return sum;
  
}

int main() {
  int num1, num2;
  int arr1[] = {INT_MAX, 2147483647, 1, 42};
  int arr2[] ={2147483647, 1, 200, 1200};
  for (int i =0; i<4; i++){
    try {
    cout << safeAdd(arr1[i], arr2[i])<< endl;
  }
  catch (const char* message){
    cout << message << endl;
  }
  }
  
}

