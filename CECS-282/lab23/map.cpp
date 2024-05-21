/*
*Richard Nguyen 
*Lydia Yang
*Alex Melford
*Emanuel Ruiz
*Demo: 5:00
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//Use typedef to define StrIntMap as map<string,int>
//YOUR CODE
typedef map<string, int> StrIntMap;

//Function countWord to count the number of word use in as filestream and words as a map container
//YOUR CODE
void countWords(istream& in, StrIntMap& word) {

  string s;

  while (cin >> s) { word[s] = word[s] + 1; }

}       


int main()
{
  map<string, int> x;
string str[] = {"I", "hate", "summers", "I", "hate", "heat"};
 
for (int i = 0; i < 6; i++)
{
   x[str[i]] = x[str[i]] + 1;
}
map<string, int>::iterator iter;
for (iter = x.begin(); iter != x.end(); ++iter)
{
   cout << iter->first << " - " << iter->second << endl;
}
  
 

}
