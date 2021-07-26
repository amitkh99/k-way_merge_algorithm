#define _CRT_SECURE_NO_WARNINGS
#include "Array.h"
#include<string.h>
using namespace std;
using namespace ARRAY;

int main() {
	string inFileNameString;
	string outFileNameString;
	int size;
	int k;
	char* inFileName;
	char* outFileName;
	
	//cout << "Please enter the number of lines in the file" << endl;
	size = checkInputFromUser();
	
	//cout << "Please enter k" << endl;
	k = ARRAY::checkInputFromUser();

	//cout << "Please enter input file name" << endl;
	cin >> inFileNameString;
	inFileName = new char[inFileNameString.length() + 1];
	strcpy(inFileName, inFileNameString.c_str()); //convert the name received as a string into a char*

	//cout << "Please enter an output file name" << endl;
	cin >> outFileNameString;
	outFileName = new char[outFileNameString.length() + 1];
	strcpy(outFileName, outFileNameString.c_str()); //convert the name received as a string into a char*

	Array initialArray(inFileName, size, k); //Class where the array is held
	initialArray.kMergeAlgorithm(); //Recursive sorting algorithm
	initialArray.copyArrayToFile(outFileName); //Write the sorted array to a file
	delete[] inFileName;
	delete[] outFileName;

	return 1;
}