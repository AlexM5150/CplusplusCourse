#include <iostream>
#include <iomanip>

using namespace std;

#define LONGESTSTRING 18

int main() {
	long value1 = 200000, value2;
	long* longPtr;
	longPtr = &value1;
	cout << setw(LONGESTSTRING);
	cout << setw(LONGESTSTRING) << "Value in longPtr: " << *longPtr << endl;
	value2 = *longPtr;
	cout << setw(LONGESTSTRING) << "value2: " << value2 << endl;
	cout << setw(LONGESTSTRING) << "value1 address: " << &value1 << endl;
	cout << setw(LONGESTSTRING) << "longPtr address: " << longPtr << endl;
}