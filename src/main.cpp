#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include <chrono>

#include "BruteForce.h"
#include "RabinKarp.h"
#include "KMPSearch.h"

using namespace std;

void fixText(string &text, int start, int len){
	text.insert((start+len), "</span>");
	text.insert((start), "<span style = \"background-color: #FFFF00\">");
}

void printTimes(int matches, double BFtime, double KMPtime, double RKtime, string oFile){
	ofstream myFile(oFile, ios_base::app);
	myFile << "There were " << matches << "matches.<br>";
	myFile << "Brute force took " << BFtime << " microseconds.<br>";
	myFile << "Knuth-Morris Pratt took " << KMPtime << " microseconds.<br>";
	myFile << "Rabin Karp took " << RKtime << " microseconds.<br>";
	myFile << "</body></html>";
	myFile.close();
}

void printHTML(string text, vector<int> locations, string oFile){ //print out time as well
	ofstream myFile(oFile);
	myFile << "<!DOCTYPE html><html><head></head><body>";
	myFile << text;
	myFile << "<br><br><br>";
	myFile.close();
}

string getTextFromFile(string path){
	ifstream infile(path);
	stringstream textBuffer;
	textBuffer << infile.rdbuf();
	return textBuffer.str();
}

//indices start from 1
//should it handle lowercase?
void testStringSearches(string txtF, string ptFile, string oFile){
	string text, pattern, origText;
	vector<int> timeToFindFirst;
	vector<int> timeToFindAll;

	text = getTextFromFile(txtF);
	pattern = getTextFromFile(ptFile);
	//getting rid of newline char at the end
	text.erase(remove(text.begin(), text.end(), '\n'), text.end());
	pattern.erase(remove(pattern.begin(), pattern.end(), '\n'), pattern.end());

	auto begin = chrono::steady_clock::now();
	BruteForce bf1(text, pattern);
	vector<int> BFall = bf1.findAll();
	auto end = chrono::steady_clock::now();
	chrono::duration<double, micro> timeMilli = end - begin;
	auto BFtime = timeMilli.count();
	cout<<"BruteForce: time diff in microsecs is " << timeMilli.count()<<endl;
	int BFfirst = bf1.search();

	KMPSearch kmp1(text, pattern);
	int KMPfirst = kmp1.search();
	vector<int> KMPall = kmp1.findAll();

	assert((BFfirst == KMPfirst) && (BFall == KMPall));
	for(int i = KMPall.size(); i >0; i--) //making it html friendly
		fixText(text, KMPall[i-1], pattern.size());

	printHTML(text, KMPall, oFile);

	begin = chrono::steady_clock::now();
	KMPSearch kmp(text, pattern);
	kmp.findAll();
	end = chrono::steady_clock::now();
	timeMilli = end - begin;
	auto KMPtime = timeMilli.count();
	cout<<"KMP: time diff in microsecs is " << timeMilli.count()<<endl;

	begin = chrono::steady_clock::now();
	RabinKarp rk(text, pattern);
	rk.findAll();
	end = chrono::steady_clock::now();
	timeMilli = end - begin;
	auto RKtime = timeMilli.count();
	cout<<"RabinKarp: time diff in microsecs is " << timeMilli.count()<<endl;
	
	printTimes(KMPall.size(), BFtime, KMPtime, RKtime, oFile);
}

int main(int argc, char **argv){
	if(argc != 4){
		cout << "./SearchComparisons <text file> <pattern file> <output file name>"<<endl;
	}
	testStringSearches(argv[1], argv[2], argv[3]);

	return 0;
}
