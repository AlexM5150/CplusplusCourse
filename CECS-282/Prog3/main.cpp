//  Alex Melford
//  Class (CECS 282-01)
//  Project Name (Prog 3 – Student List)
//  Due Date (10/11/2021)
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <time.h>
#include <string>
#include <cstring>
#include "myDate.h"
#include <iomanip>
#include <algorithm>

using namespace std;

int GregJulian(int month, int day, int year) {
	int I, J, K, JD;
	
	I = year;
	J = month;
	K = day;
	
	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return JD;
}

void JulianGreg(int JD, int& month, int& day, int& year) {
	int I, J, K, L, N;
	
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	
	year = I;
	month = J;
	day = K;
}


struct Student{
  char name[20];
  int student_id;
  char grade;
  myDate birthday;
  string homeTown;
};

Student* createStudent(string studentName, int studentID, char studentGrade, myDate studentBirthday, string studentHomeTown){
    Student* student_pointer = new Student;
    strcpy(student_pointer->name, studentName.c_str());
    student_pointer->student_id = studentID;
    student_pointer->grade = studentGrade;
    student_pointer->birthday = studentBirthday;
    student_pointer->homeTown = studentHomeTown;
    return student_pointer;
}

int randID(){
    int ID = ((rand() % 899)+100);
    return ID;
}

myDate randDate(){
    int M;
    int D;
    int Y;
    int start = GregJulian(1, 1, 2000);
    int end = GregJulian(12, 31, 2024);
    int diff = abs(start - end);
    int jd = ((rand() % diff)+start);
    JulianGreg(jd, M, D, Y);
    myDate rdate(M ,D ,Y);
    return rdate;
    
}

void display(Student *student[], int size) {
    cout << setw(20) << left << "Name" << setw(15) << left << "Student ID" << setw(10) << left << "Grade" << setw(25) << left << "BirthDay" << setw(20) << left << "Home Town" << endl;
    cout << "________________________________________________________________________________" << endl;
  
  for (int i = 0; i < size; i++) {
    string bday = student[i]->birthday.printDate();
    cout << setw(20) << left << student[i]->name << setw(15) << left << student[i]->student_id << setw(10) << left << student[i]->grade << setw(25) << left << bday << setw(20) << left << student[i]->homeTown << endl;
    }
  
}
bool compareID(Student *s1, Student *s2){
    if (s1->student_id < s2->student_id)
        return 1;
    else
        return 0;
}

bool compareName(Student *s1, Student *s2){
    int comp = strcmp(s1->name, s2->name);
    if (comp < 0) 
        return 1; 
    return 0;
}

bool compareGrade(Student *s1, Student *s2){
    if (s1->grade < s2->grade)
        return 1; 
    return 0;
}

bool compareDate(Student *s1, Student *s2){
    int M1 = s1->birthday.getMonth();
    int D1 = s1->birthday.getDay();
    int Y1 = s1->birthday.getYear();
    int JD1 = GregJulian(M1, D1, Y1);

    int M2 = s2->birthday.getMonth();
    int D2 = s2->birthday.getDay();
    int Y2 = s2->birthday.getYear();
    int JD2 = GregJulian(M2, D2, Y2);
    if (JD1 < JD2)
        return 1; 
    return 0;
}

bool comparehomeTown(Student *s1, Student *s2){
    int comp = strcmp(s1->homeTown.c_str(), s2->homeTown.c_str());
    if (comp < 0) 
        return 1; 
    return 0;
}

int main()
{
    srand(time(0));
    const int size = 10;
    Student *myClass[size];
    myClass[0] = createStudent("Sponge Bob", randID(), 'A', randDate(), "Bikini Bottom");
    myClass[1] = createStudent("Fred Flinstone", randID(), 'D', randDate(), "Bedrock");
    myClass[2] = createStudent("Timmy Turner", randID(), 'C', randDate(), "Dimmsdale");
    myClass[3] = createStudent("Perry Platypus", randID(), 'C', randDate(), "Danville");
    myClass[4] = createStudent("Jimmy Neutron", randID(), 'A', randDate(), "Retroville");
    myClass[5] = createStudent("Charlie Brown", randID(), 'B', randDate(), "Hennepin County");
    myClass[6] = createStudent("Patrick Star", randID(), 'F', randDate(),  "Bikini Bottom");
    myClass[7] = createStudent("Bart Simpson", randID(), 'D', randDate(),  "Springfield");
    myClass[8] = createStudent("Lisa Simpson", randID(), 'A', randDate(),  "Springfield");
    myClass[9] = createStudent("Stewie Griffen", randID(), 'A', randDate(), "Quahog");
    //display(myClass, size);
    int choice;
    bool flag = true;
    while (flag != false){
        cout << "Welcome to Student List!\n";
        cout << " 1 - Display list sorted by Name\n";
        cout << " 2 - Display list sorted by Student ID\n";
        cout << " 3 - Display list sorted by Grade\n";
        cout << " 4 - Display list sorted by Birthday\n";
        cout << " 5 - Display list sorted by Home Town\n";
        cout << " 6 - Exit\n";

        cin >> choice;

        if (choice == 1){
           sort(myClass, myClass+size, compareName);
           display(myClass, size);
        }
        else if (choice == 2){
           sort(myClass, myClass+size, compareID);
           display(myClass, size);
        }
        else if(choice == 3){
           sort(myClass, myClass+size, compareGrade);
           display(myClass, size);
        }
        else if (choice == 4){
           sort(myClass, myClass+size, compareDate);
           display(myClass, size);
        }

        else if (choice == 5){
           sort(myClass, myClass+size, comparehomeTown);
           display(myClass, size);
        }
   
        else{
            flag = false;
        }
    }

    return 0;
}