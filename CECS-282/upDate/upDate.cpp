//  Alex Melford
//  Class (CECS 282-01)
//  Project Name (Prog 4 – Overloading Operators)
//  Due Date (11/1/21)
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "upDate.h"
using namespace std;

int upDate::dateCount = 0;

ostream& operator<<(ostream& out, upDate D){
    out << D.datePtr[0] << "/" << D.datePtr[1] << "/" << D.datePtr[2];
    return out;
}

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

upDate::upDate(){
    datePtr = new int[3];
    
    datePtr[0] = 5;
    datePtr[1] = 11;
    datePtr[2] = 1959;
    dateCount++;
}

upDate::upDate(int month, int day, int year){
   datePtr = new int[3];
   dateCount++;
   setDate(month, day, year);
}

upDate::upDate(const upDate& D){
    datePtr = new int[3];
    datePtr[0] = D.getMonth();
    datePtr[1] = D.getDay();
    datePtr[2] = D.getYear();
    dateCount++;
}

void upDate::operator=(upDate D){
    datePtr[0] = D.getMonth();
    datePtr[1] = D.getDay();
    datePtr[2] = D.getYear();
    
}

upDate upDate::operator+(int N){
    upDate temp = upDate(*this);
    int inc = temp.julian() + N;
    Julian2Greg(inc, temp.datePtr[0], temp.datePtr[1], temp.datePtr[2]);
    return temp;
}

upDate upDate::operator+=(int N){
    *this = *this + N;
    return *this;
}

upDate upDate::operator-=(int N){
    *this = *this - N;
    return *this;
}

upDate upDate::operator-(int N){
    upDate temp = upDate(*this);
    int dec = temp.julian() - N;
    Julian2Greg(dec, temp.datePtr[0], temp.datePtr[1], temp.datePtr[2]);
    return temp;
}

upDate operator+(int N, const upDate& D){
    upDate temp = upDate(D);
    int inc = temp.julian() + N;
    Julian2Greg(inc, temp.datePtr[0], temp.datePtr[1], temp.datePtr[2]);
    return temp;
}

int upDate::operator-(upDate D){
    int j1 = this->julian();
    int j2 = D.julian();
    int diff = abs(j1 - j2);
    return diff;
}

upDate operator-(int N, const upDate& D){
    upDate temp = upDate(D);
    int dec = temp.julian() - N;
    Julian2Greg(dec, temp.datePtr[0], temp.datePtr[1], temp.datePtr[2]);
    return temp;
}

upDate upDate::operator++(){
    int inc = this->julian() + 1;
    Julian2Greg(inc, datePtr[0], datePtr[1], datePtr[2]);
    return *this;
}

upDate upDate::operator--(){
    int inc = this->julian() - 1;
    Julian2Greg(inc, datePtr[0], datePtr[1], datePtr[2]);
    return *this;
}

upDate upDate::operator++(int N){
    upDate incDate = *this;
    ++*this;
    return incDate;        
}

upDate upDate::operator--(int N){
    upDate decDate = *this;
    --*this;
    return decDate;
}

bool upDate::operator==(const upDate& D){
    if(*this - D == 0)
        return true;
    else
        return false;
}

bool upDate::operator>(const upDate& D){
    if(this->julian() - D.julian() > 0)
        return true;
    else
        return false;
}

bool upDate::operator<(const upDate& D){
    if(this->julian() - D.julian() < 0)
        return true;
    else
        return false;
}

int upDate::GetDateCount(){
    return dateCount;
}

upDate::~upDate(){
    delete [] datePtr;
    dateCount--;
}

upDate::upDate(int j){
    Julian2Greg(j, datePtr[0], datePtr[1], datePtr[2]);
}

int upDate::julian() const{
    int jdate = Greg2Julian(datePtr[0], datePtr[1], datePtr[2]);
    return jdate;
}

int upDate::getMonth() const{
    return datePtr[0];
}
int upDate::getDay() const{
    return datePtr[1];
}
int upDate::getYear() const{
    return datePtr[2];
}

void upDate::setDate(int month, int day, int year){
   datePtr[0] = month;
   datePtr[1] = day;
   datePtr[2] = year;
   int jdate = Greg2Julian(datePtr[0], datePtr[1], datePtr[2]);
   Julian2Greg(jdate, datePtr[0], datePtr[1], datePtr[2]);
   if (datePtr[0] != month || datePtr[1] != day || datePtr[2] != year){
       datePtr[0] = 5;
       datePtr[1] = 11;
       datePtr[2] = 1959;
   }
}

string upDate::getMonthName(){
    string months[12] = {"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};
    string month;
    int arrSize = sizeof(months)/sizeof(months[0]);
    for (int i = 0; i < arrSize; i++){
        if (datePtr[0] == i+1)
            month = months[i];
    }
    return month;
}