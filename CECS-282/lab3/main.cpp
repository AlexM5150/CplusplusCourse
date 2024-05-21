#include <iostream>
#include "Can.h"
using namespace std;



int main() {
  
  Can c1(12,"coke");
  Can c2(16,"Mango Monster");
  Can c3(8, "Red Bull");
  Can c4(16, "Bang");
  Can c5(16, "Venom");
  Can c6(12, "Jolt Cola");
  
  Can arr[6] = {c1, c2, c3, c4, c5, c6};
  int totalWeight = 0;

  for(int i =0; i <6; i++){
    arr[i].display();
    totalWeight += arr[i].getWeight();
  }
  cout << "The total amount of weight " << totalWeight <<" ounces" << endl;
  return 0;


}