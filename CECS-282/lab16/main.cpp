//Zach Brown
//Alex Melford
//Purnima Jain 
//Demo Time: 5:26 PM

#include <iostream>
#include "Can.h"

Can max(Can a, Can b){
  if (a.get_ounces() > b.get_ounces()) 
		return a;
  return b;
	
}
int main()

{

    Can c1("Coke",12);

    Can c2("beans",20);

    Can c3 = c2;

    {

        Can c4("juice", 32);

        Can c5("juice", 12);

        c4 = c5;

        cout << "\n--------Can #4->";

        c4.display();

        cout << "\n--------Can #5->";

        c5.display();

    }

 

    c3 = max(c1, c2);

    cout << "\n--------Max size->";

    c3.display();

   

    // the following code does not compile - why?

    //  cout << "--------Can #4->";

    //  c4.display();              

    //  cout << "--------Can #5->";

    //  c5.display();

}