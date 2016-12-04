#include <iostream>
#include <string>

#include "BruteForce.h"
#include "RabinKarp.h"
#include "KMPSearch.h"

using namespace std;

void printFoundText(string text, int start, int len){
	text.insert((start+len), " ] ");
	text.insert((start), " [ ");
	cout << "Location in text is " << text << endl;
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
	cout << "Brute Force: ";
	if(ret == -1)
		cout << "Couldn't find pattern in text!" << endl;
	else
		 printFoundText(text, ret, pattern.size());

	RabinKarp rk(text, pattern);
	ret = rk.search();
	cout << "Rabin-Karp: ";
	if (ret == -1) cout << "Couldn't find pattern in text!" << endl;
	else printFoundText(text, ret, pattern.size());

	KMPSearch kmp(text, pattern);
	ret = kmp.search();
	cout << "KMP: ";
	if (ret == -1) cout << "Couldn't find pattern in text!" << endl;
	else printFoundText(text, ret, pattern.size());


	return 0;
}
