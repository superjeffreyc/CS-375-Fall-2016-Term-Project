#include <iostream>
#include <string>

#include "BruteForce.h"

using namespace std;

string printFoundText(string &text, int start, int len){
	text.insert((start+len), " ] ");
	text.insert((start), " [ ");
	return text;
}

int main(){
	string text;
	string pattern;
	
	cout << "Enter text to search and hit <Enter>" << endl;
	cin >> text;
	
	cout << "Enter pattern to serarch for and hit <Enter>" << endl;
	cin >> pattern;
	
	BruteForce test(text, pattern);

	int ret = test.search();
	if(ret == -1)
		cout << "Couldn't find pattern in text!" << endl;
	else
		cout << " Location in text is " << printFoundText(text, ret, 
											pattern.size()) << endl;

	return 0;
}
