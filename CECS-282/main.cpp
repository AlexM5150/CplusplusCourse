#include <iostream>
#include <string>
using namespace std;

class Can{
  private:
    int weight;
    string contents;
  public:
    Can();
    Can(string, int);
    void display();
    int getWeight();
    };

Can::Can(){
  string contents = " ";
  int weight = 0;
}

Can::Can(string c,int v){
  contents = c;
  weight = v;
}

void Can::display()
{
  cout<< weight << " ounce can of " << contents << endl;
}

int Can::getWeight(){
  return weight;
}



int main() {
  std::cout << "Hello World!\n";
  Can c1("Pepsi",12);
  Can c2("Pears",16);
  Can c3("mustard",32);
  Can c4("apple juice",40);

  c1.display();
  c2.display();
  c3.display();
  c4.display();

  int totalWeight = c1.getWeight()+ c2.getWeight() + c3.getWeight() + c4.getWeight();
  cout << "The total amount of weight " << totalWeight <<" ounces" << endl;
  
}