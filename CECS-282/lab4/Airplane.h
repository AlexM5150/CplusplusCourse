#include <string>
using namespace std;

class Airplane {
  private:
    string model;
    int altitude;
    int minAltitude;
    int maxAltitude;
  public:
    Airplane(string m, int minA, int maxA);
    void display();
    int getAltitude();
    void setAltitude();
    bool crash(Airplane);
};