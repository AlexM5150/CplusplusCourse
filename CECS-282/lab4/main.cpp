#include <iostream>
#include "Airplane.h"
#include <time.h>
using namespace std;

int main() {
  srand(time(0));
  double crashes = 0;
  for (int i = 0; i < 1000; i++) {
    Airplane a1("Boeing 747",  2000, 5000);
    Airplane a2("MIG Fighter", 4000, 9000);
    a1.setAltitude();
    a2.setAltitude();
    if (a1.crash(a2)) {
      crashes ++;
      cout << "Crash " << crashes << " occurred\n";
      a1.display();
      a2.display();
      cout << "\n\n";
    }
  }

  float percentageOfCrashes = (crashes/1000)*100;
  cout << "Percentage of crashes: " << percentageOfCrashes << "%";
}