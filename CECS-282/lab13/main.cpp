/*
Alex Melford
Leyu Wondafrash
Dhruv Savla
Emanuel RUiz
*/
#include <iostream>

 

using namespace std;

const int SIZE = 5;

 
int main () {

   int  grade[SIZE] = {10, 20, 30,25,22};
   int total = 0;
   int average = 0; 
   int *arrPtr[SIZE];
   

   for (int i = 0; i < SIZE; i++) {

      arrPtr[i] = &grade[i];

      cout << "Value of grade[" << i << "] = ";

      cout << grade[i] << endl;
      total+= (*arrPtr)[i];
      cout << "Value of arrPtr[" << i << "] = ";
      cout << *arrPtr[i] << endl;

   }
   average = total/SIZE;
   cout << "Average = ";
   cout << average << endl;
   for(int i = 0; i < SIZE; i++)
   {
     cout<< arrPtr + i<<endl;
     cout << arrPtr[i]<<endl;
   } 


   return 0;

}