#include <iostream>
#include <string>

#include "BruteForce.h"
#include "RabinKarp.h"
#include "KMPSearch.h"

using namespace std;

string printFoundText(string &text, int start, int len){
	text.insert((start+len), " ] ");
	text.insert((start), " [ ");
	return text;
}

int main(){
	string text, rktext, kmptext;
	string pattern;

	cout << "Enter text to search and hit <Enter>" << endl;
	cin >> text;
	rktext = text;
	kmptext = text;

	cout << "Enter pattern to serarch for and hit <Enter>" << endl;
	cin >> pattern;

	BruteForce test(text, pattern);

	int ret = test.search();
	cout << "Brute Force: ";
	if(ret == -1)
		cout << "Couldn't find pattern in text!" << endl;
	else
		cout << " Location in text is " << printFoundText(text, ret,
											pattern.size()) << endl;

	RabinKarp rk(rktext, pattern);
	ret = rk.search();
	cout << "Rabin-Karp: ";
	if (ret == -1) cout << "Couldn't find pattern in text!" << endl;
	else cout << " Location in text is " << printFoundText(rktext, ret, pattern.size()) << endl;

	KMPSearch kmp(kmptext, pattern);
	ret = kmp.search();
	cout << "KMP: ";
	if (ret == -1) cout << "Couldn't find pattern in text!" << endl;
	else cout << " Location in text is " << printFoundText(kmptext, ret, pattern.size()) << endl;


	return 0;
}
