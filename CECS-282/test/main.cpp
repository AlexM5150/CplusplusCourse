#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>


using namespace std;



int main()
{
 map<string, int> scores;
scores["Diana"] = 86;
scores["Mark"] = 80;
if (scores["Fred"] < 0)
{
   cout << "Error ";
}   
for (auto it = scores.begin(); it != scores.end(); it++)
{
   cout << "  " << it->first << ":" << it->second;
}
}