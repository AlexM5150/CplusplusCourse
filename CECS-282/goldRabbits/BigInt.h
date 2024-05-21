//    Alex Melford
//    Class (CECS 282-01)
//    Project Name (Prog 5 – BigInt)
//    Due Date (11/29/2021)
// 
//    I certify that this program is my own original work. I did not copy any part of this program from 
//    any other source. I further certify that I typed each and every line of code in this program.

#ifndef BIG_INT_H
#define BIG_INT_H

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class BigInt{
    private:
        vector<char> storage;
    public:
        BigInt();
        BigInt(string s);
        BigInt(int n);
        vector<char> getV();
        BigInt operator+(BigInt) const;
        BigInt operator-(BigInt) const;
        BigInt operator++(int);
        bool operator<(const BigInt&) const;
        bool operator==(const BigInt&) const;
        bool operator ==(int);
        bool operator<=(const BigInt&) const;
        bool operator<=(int);
        BigInt operator+(int);
        BigInt operator-(int);
        friend ostream & operator<<(ostream &, BigInt);
        void print();
};

#endif