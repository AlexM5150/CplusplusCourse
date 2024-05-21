/*
Anh Huynh
Alex Melford
Ari Montes
Kevin Thai
time: 5:05
*/

#include <iostream>

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

int main() {
  int start = Greg2Julian(1, 1, 1000);
  int end = Greg2Julian(12,25, 1500);
  int m, d, y;
  int jd = 0;
  m = 23;
  d =12;
  y = 2007;
  /*int j = Greg2Julian(m, d, y) + 30;
  int diff = j - Greg2Julian(m, d, y);
  Julian2Greg(j, m, d, y);
  cout<<m <<", "<< d<<", "<< y;
  cout << diff;*/
  int x = Greg2Julian(23, 12, 2007);
  cout<<x;
  Julian2Greg(x, m, d, y);
  cout<<m<<d<<y;


  /*for (int i = start; i <= end; i++) {
    Julian2Greg(i, m, d, y);

    if (d == 29 && m == 2) {
      cout << y << " is a leapyear" << endl;
    }
  }*/
}