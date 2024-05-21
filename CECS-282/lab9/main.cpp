/*Richard Nguyen
Alex Melford
Steven Nguyen
Jose Fuentes
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car{
  string make, model, manufacture, color;
  int year, mileage, mpg, price;
};

void display(struct Car arr[]) {
  for (int i = 0; i < 5; i++) {
    cout <<"Make: " <<  arr[i].make << endl;
    cout <<"Model: " << arr[i].model << endl;
    cout <<"Manufacture: " <<  arr[i].manufacture << endl;
    cout <<"Color: " << arr[i].color << endl;
    cout <<"Year: " << arr[i].year << endl;
    cout <<"Mileage: " << arr[i].mileage << endl;
    cout <<"MPG: " << arr[i].mpg << endl;
    cout <<"Price: " << arr[i].price << endl;
    cout << endl;
  }
  
}

	
int main() {
  struct Car carLot[5] = { {"Toyota", "Camry","Toyta","Grey", 2007,178000,28,3600}, {"Audi", "R8","Audi","Black", 2018,174441,25,3200},
  {"Subaru", "BRZ","Subaru","Blue", 2015,33423,23,27000},
  {"Scion", "FRS","Toyota","White", 2014,84423,20,3000200},
  {"Subaru", "WRX","Subaru","white", 2020,35320,26,31000} };
  display(carLot);
  // Car *cptr = &carLot[0];
}