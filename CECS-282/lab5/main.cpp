#include <time.h>
#include <iostream>
#include <algorithm>
using namespace std;

int sort6(int &a, int &b,  int &c, int&d, int&e, int &f){
  int arr [6] = {a, b, c, d, e, f};
  int  size = sizeof(arr) /sizeof(arr[0]);
  sort(arr, arr+size); 
  int sum = 0;
  cout<< "After sorting:"<<endl;
  for (int i = 0; i < 6; i++){
    cout << arr[i] << endl;
  }
  cout<<"Total sum of the numbers:"<<endl;
  return a + b + c + d + e + f;
}


int main() {
  srand(time(0));
  int a = ((rand() % 500)+100);
  int b = ((rand() % 500)+100);
  int c = ((rand() % 500)+100);
  int d = ((rand() % 500)+100);
  int e = ((rand() % 500)+100);
  int f = ((rand() % 500)+100);
  
  int arr [6] = {a, b, c, d, e, f};

  cout<< "Before sorting:"  <<endl;
  for (int i = 0; i < 6; i++){
    cout << arr[i] << endl;
  }
  
  cout  << sort6(a,b,c,d,e,f);
   
  
}