#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  //Expecting eactly two arguments. Error if that doesn't hold
  
  if(argc != 3) {
    cout << "Usage <executable> <first strting> <second string> \n";
    return 0;
  }

  char* firstString = argv[1];
  char* secondString = argv[2];

  //Printing strings
  cout << "============================" << "\nPrinting strings " << endl << "============================" << endl;
  cout << firstString << endl;
  cout << secondString << endl;

  string s1(firstString);
  string s2(secondString);

  //Is one a permutation of the other?
  //Pick the smaller string
  string smallStr = (s1.size() < s2.size()) ? s1:s2;
  string largeStr = (s1.size() < s2.size()) ? s2:s1; 

  //Sort both strings
  std::sort(smallStr.begin(), smallStr.end());
  std::sort(largeStr.begin(), largeStr.end());

  cout << "=======================x=====" << "\nPrinting sorted strings " << endl<< "============================" << endl;
  cout << smallStr << endl;
  cout << largeStr << endl;

  //See if smallstring characters exists in lareStr
  int counter1 = 0;
  int counter2 = 0;
  int match = 0;

  while (counter1 < smallStr.size() && counter2 < largeStr.size()) {
    if(smallStr[counter1] == largeStr[counter2]) {
      counter1++;
      counter2++;
      match++;
    } else if (smallStr[counter1] < largeStr[counter2]) {
      counter1++;
    } else {
      counter2++;
    }
  }
 
  if(match == smallStr.size())
    cout << "The smaller string is a permutation of parts of larger\n";
  else 
    cout << "The smaller string is NOT a permutation of parts of larger \n";
}

