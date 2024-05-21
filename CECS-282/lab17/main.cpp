/*
Alex Melford
Emanuel Ruiz
Kevin Thai
Andy Wong
Demo time : 5:36
*/
#include <string>
#include <iostream>

#include "LinkedList.h"
#include "Student.h"

using namespace std;

int main(int argc, const char * argv[]) {

   

    std::cout << "Hello, World!\n";

    int a = 3;

    string s = "M";

    cout << s << a;

    s = s + to_string(a);

    cout << s;

    list myList;

    cout << myList.size();
    Student s1("John");
    s1.setGpa(3.6);
    Student s2("Tom");
    s2.setGpa(3.7);
    Student s3("Johnny");
    s3.setGpa(3.8);  
    Student s4("Harold");
    s4.setGpa(2.9);
    Student s5("James");
    s5.setGpa(3.0);
    Student s6("Jack");
    s6.setGpa(4.0);
    Student s7("Bob");
    s7.setGpa(5.0);


    myList.add(s1);

    myList.add(s2);

    myList.add(s3);

    myList.add(s4);

    myList.addHead(s5);

    myList.addHead(s6);

    myList.addHead(s7);

    cout << "\nSize..." << myList.size()<< endl;

    myList.display();

    cout << "\nSize..." << myList.size()<< endl;

    myList.display();

    cout << "\nDelelte Tail.. ";
    
    myList.deleteTail().output();

    cout << "\nSize..." << myList.size()<< endl;

    myList.display();

    return 0;

}