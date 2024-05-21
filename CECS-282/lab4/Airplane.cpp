#include <iostream>
#include <cmath>
#include "Airplane.h"

using namespace std;

Airplane::Airplane(string m, int minA, int maxA) {
  model = m;
  minAltitude = minA;
  maxAltitude = maxA;
};

void Airplane::display() {
  cout << model << " | Altitude: " << altitude << endl;
};

void Airplane::setAltitude() { 
  altitude = (rand() % (maxAltitude - minAltitude + 1) + minAltitude);
}

int Airplane::getAltitude() { 
  return altitude;
}

bool Airplane::crash(Airplane a) {
  int altitudeDiff = altitude - a.getAltitude();
  if (abs(altitudeDiff) <= 200) {
    return true;
  }
  return false;

};