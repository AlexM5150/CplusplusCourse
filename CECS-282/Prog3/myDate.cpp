//  Alex Melford
//  Class (CECS 282-01)
//  Project Name (Prog 2 – myDate Object)
//  Due Date (9/27/21)
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "myDate.h"
using namespace std;

int Greg2Julian(int month, int day, int year) {
	int I, J, K, JD;
	
	I = year;
	J = month;
	K = day;
	
	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return JD;
}

void Julian2Greg(int JD, int& month, int& day, int& year) {
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

myDate::myDate(){
    M = 5;
    D = 11;
    Y = 1959;
}

myDate::myDate(int month, int day, int year){
   M = month;
   D = day;
   Y = year;
   int jdate = Greg2Julian(M, D, Y);
   Julian2Greg(jdate, M, D, Y);
   if (M != month || D != day || Y != year){
       M = 5;
       D = 11;
       Y = 1959;
   }
}

void myDate::display(){
    string months[12] = {"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};
    int arrSize = sizeof(months)/sizeof(months[0]);
    for (int i = 0; i < arrSize; i++){
        if (M == i+1)
            cout << months[i] << " ";        
    }
    cout << D << ", " << Y;
    
}

void myDate::increaseDate(int N){
    int inc = Greg2Julian(M, D, Y) + N;
    Julian2Greg(inc, M, D, Y);
}

void myDate::decreaseDate(int N){
    int dec = Greg2Julian(M, D, Y) - N;
    Julian2Greg(dec, M, D, Y);
}

int myDate::daysBetween(myDate Date){
    int j1 = Greg2Julian(M, D, Y);
    int j2 = Greg2Julian(Date.M, Date.D, Date.Y);
    int diff = abs(j1 - j2);
    return diff;
}

int myDate::getMonth(){
    return M;
}
int myDate::getDay(){
    return D;
}
int myDate::getYear(){
    return Y;
}
int myDate::dayOfYear(){
    int current = Greg2Julian(M, D, Y);
    int start = Greg2Julian(1, 1, Y);
    int diff = current - start + 1;
    return diff;
}

string myDate::dayName(){
    string days[7] = {"Monday", "Tuesday", "Wednsday", "Thursday", "Friday", 
    "Saturday", "Sunday"};
    string day;
    int jweek = Greg2Julian(M, D, Y) % 7;
    for (int i = 0; i < 7; i++){
        if (jweek == i)
            day = days[i];            
    }
    return day;
}

string myDate::printDate(){
    string months[12] = {"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};
    string month;
    string date;
    int arrSize = sizeof(months)/sizeof(months[0]);
    for (int i = 0; i < arrSize; i++){
        if (M == i+1)
           month = months[i];        
    }
    date = month + " " + to_string(D) + ", " + to_string(Y);
    return date;
}