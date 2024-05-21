// Breanna Le
//Alex Melford
//Jonathan Garduno
//Time: 5:15PM
#include <iostream>
using namespace std;

void strcpy(char t[], char s[]){
  cout << "Entering strcpy" << endl;
  int i = 0;
  while(s[i] != '\0'){
    t[i] = s[i];
    i++;
  }
  t[i] = '\0';
}

int strlen(char c[]){
  cout << "Entering strlen" << endl;
  int count = 0;
  int i = 0;
  while(c[i] != '\0'){
    count++;
    i++;
  }
  return count;
}

char* strcat(char *dest, char *source){
  cout << "Entering strcat" << endl;
  char* ptr = dest + strlen(dest);
  
  while(*source != '\0'){
    *ptr++ = *source++;
  }
  *ptr = '\0';
  return dest;
}



int main() {
  char test[5];
  char str[5] = "hel";
  //char ing[5] = "lo";
  strcpy(test, "Hello");
  cout << test << endl;
  cout << strlen(test) << endl;
  strcat(str, "lo");
  cout << str << endl;

}