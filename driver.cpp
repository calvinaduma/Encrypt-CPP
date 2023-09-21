/*	Calvin Aduma
	caduma | Section 001 | Nushrat Humaira
	F20
	11.09.20
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "encrypt.h"
using namespace std;

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);

    int row = 0, col = 0;

    vector<char> vec = readData(in);

    findFloorCeiling(row, col, vec.size());

    Encrypt(vec, col);
	cout << endl;;

    return 0;
}
