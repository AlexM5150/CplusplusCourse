//Alex Melford
//Justin Galbraith
// Ari Montes 
// Andy Wong
// Demo Time : 5:35
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main() {
  map<string, int> wordCount;
  ifstream myfile;
  myfile.open("paragraph.txt");
  string word;
  while(!myfile.eof()) {
    myfile >> word;

    for (int i = 0; i < word.length(); i++){
      if(ispunct(word[i]) || isdigit(word[i])) {
        word.erase(i--, 1);
      }
      word[i] = tolower(word[i]);
    }

    auto key = wordCount.find(word);
    if (wordCount.find(word) == wordCount.end()){
      wordCount.insert(pair<string, int>(word, 1));
    }
    else{
      wordCount[word] += 1;
    }
  }

    for (auto iterator = wordCount.cbegin(); iterator != wordCount.cend(); ++iterator){
      cout << iterator->first << ": " << iterator->second << endl;
    }

  myfile.close();
  
} 