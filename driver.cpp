#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "rabinkarp.h"

using namespace std;

string getInput(char * fileName);

int main(int argc, char * argv[]) {

	// Read pattern and text from files
	string pattern = getInput(argv[1]);
	string text = getInput(argv[2]);
	
	// Run Rabin-Karp Pattern Searching Algorithm
	rabinKarpSearch(pattern, text);

	return 0;
}

/*
 *
 */
string getInput(char * fileName) {
	string content, temp;
	
    ifstream inputFile(fileName);

    while (getline(inputFile, temp)) {
		content += temp;
    }
    
    inputFile.close();
    
    return content;
}