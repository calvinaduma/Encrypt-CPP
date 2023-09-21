/*	Calvin Aduma
	caduma | Section 001 | Nushrat Humaira
	F20
	11.09.20
*/

#include "encrypt.h"
#include <cmath>

using namespace std;
// this function reads the data from the file and stores it into a vector array that contains no spaces
// input: address of a file
// output: a vector array of chars
vector<char> readData(ifstream& file){
	string fileContent;
	vector<char> editedFileContent;
	getline(file, fileContent); // reads content of file into fileContent
	int s=fileContent.size(); // stores size of string
	for (int i=0; i<s; i++){
		if (fileContent[i]!=32 && fileContent[i]!=10){
			editedFileContent.push_back(fileContent[i]); // stores only the characters and no the spaces or new line at end
		}
	}
	return editedFileContent;	
}
// this function sets the values for the number of rows and columns the vector
// array will have
// input: the address of 2 integers created in driver class; integer for size
void findFloorCeiling(int &r, int &c, int size){
	double square = sqrt(size); // square root of vector size
	string squareConvert = to_string(square); // converts to string for digit extraction
	char rNot, cNot; // variables for row and column numbers 
	rNot = squareConvert[0]; // first entry of string stored for row 
	cNot = squareConvert[2]; // third entry of string stored for column
	r = rNot-48; // subtract 48 to get actual decimal number since rNot is a char
  	c = cNot-48; // same as rNot but cNot
}
// this function prints the contents of the vector array
// input: vector array of type char; integer for number of columns
// outuput: void
void Encrypt(vector<char> vectorArray, int c){
	int s = vectorArray.size();
	int i=0, j=0, loop=1;
	while (loop){ // loop to print encrypted message
		cout << vectorArray[i];
		i+=c; // adds the column number to index of array to print correct encryption
		if (i>s){ // creates a carousel like loop to continue printing encryption
			j++; // similar to number of rows in vector
			i=j; // resets i to complete carousel effect
			cout << " ";
		}
		if (i==s-1){ // when i = size of vector program ends
			cout << vectorArray[i]; // necessary to print last char of encrpytion.
			break;
		}
	}	
}
