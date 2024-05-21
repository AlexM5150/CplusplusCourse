// Sopheak Chim 
//Breanna Le
//Alex Melford 
//Chris Maude
//Demo Time: 4:56 PM
#include <iostream>

using namespace std;

double IterativePow(double iNum, int iPower){
  double result = 1.0;
  for (int i = 0; i < iPower; i++){
    result *= iNum;
  }
  return result;
}

double RecursivePow(double iNum, int iPower) {
  if (iPower != 0) {
    return iNum*RecursivePow(iNum,iPower-1); 
  }
  else {
    return 1.0;
  }
}
  

int main() {
	for(int lExponent = 0; lExponent < 36; lExponent++){
		double lNumber = 2.0;
		double lIterative = IterativePow(lNumber, lExponent), lRecursive = RecursivePow(lNumber, lExponent);
		cout << lNumber << " ^ " << lExponent << " = " << lIterative << " done iteratively" << endl;
		cout << lNumber << " ^ " << lExponent << " = " << lRecursive << " done recursively" <<endl;
		if(lIterative != lRecursive){
			cout << "NOT EQUAL" << endl;
		}
	}
}