#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 20; 

int populateArray(const std::string fileName, int numArray[]) {

  int arraySize = 0;

  cout << "Reading in: " << fileName << "\n";

  std::ifstream inputFile(fileName.c_str());

  // verify that the file was opened
  if( !inputFile.is_open() ) {
    std::cerr << "failed to open input file\n" ;
    return 0;
  }

  // Read the numbers from the file into the array
  while (arraySize < ARRAY_SIZE && inputFile >> numArray[arraySize]) {
    ++arraySize;
  }

  inputFile.close();

  return arraySize;
}

void printArray(int numArray[], int arraySize) {
  cout << "Printing array :";
  for( int i = 0; i < arraySize ; ++i ) { 
    std::cout << numArray[i] << ' ' ;
  }

  cout << "\n";
}

void NSquareSortArray(int numArray[], int arraySize) {
  cout << "Sorting array \n";

  for( int i = 0; i < arraySize ; ++i ) { 
    int candidate = numArray[i];
    //find the nth smallest and print
    for( int j = i; j < arraySize ; ++j ) { 
      if (candidate  > numArray[j]) {
        	candidate = numArray[j];
        	numArray[j] = numArray[i];
	        numArray[i] = candidate;
      }
    }
  }
}

void insertionSortArray(int numArray[], int arraySize) {
  cout << "Sorting array \n";

  int i, pick, j; 
  for (i = 1; i < arraySize; i++) { 
    //Pick the ith element
    pick = numArray[i]; 
    j = i-1; 
  
    // Go through all element from i downto 0
    // If its greater than "pick", move one position to the right
 
    while (j >= 0 && numArray[j] > pick) { 
      numArray[j+1] = numArray[j]; 
      j = j-1; 
    } 

    numArray[j+1] = pick; 
  } 

}

void FindMatches(int array1[], int array2[], int size1, int size2) {

  //Find matches in two sorted arrays
  int counter1 = 0;
  int counter2 = 0;
  
  while (counter1 < size1 && counter2 < size2) {
    if (array1[counter1] == array2[counter2]) {
      cout << "Found a match: " << array1[counter1] << endl;
      counter1++;
      counter2++;
    } else if (array1[counter1] < array2[counter2]){
      counter1++;
    } else {
      counter2++;
    }
    
  }
}


int main()
{

  cout << "First array processing \n";
  cout << "======================= \n";
  
  int numArray1[ARRAY_SIZE] = {0} ; // initialize to all zeroes
  string fileName1("array1.txt");
  int size1 = populateArray(fileName1, numArray1); //read in the array from the file
  printArray(numArray1, size1); //print read in array
  insertionSortArray(numArray1, size1); //sort the array
  printArray(numArray1, size1); //print sorted array
  
  cout << "======================= \n";
  
  
  cout << "Second array processing \n";
  cout << "======================= \n";
  
  int numArray2[ARRAY_SIZE] = {0} ; // initialize to all zeroes
  string fileName2("array2.txt");
  int size2 = populateArray(fileName2, numArray2); //read in the array from the file
  printArray(numArray2, size2); //print erad in array
  insertionSortArray(numArray2, size2); //sort the array
  printArray(numArray2, size2); //print sorted array
  
  cout << "======================= \n";

  cout << "Printing matches between the two \n";
  cout << "================================ \n";
  FindMatches(numArray1, numArray2, size1, size2); //find the matched elements between the two arrays and print them
}

