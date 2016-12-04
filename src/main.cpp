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

void printHTML(string text, vector<int> locations, string oFile, int matches,
				double BFtime, double KMPtime, double RKtime){
	ofstream myFile(oFile);
	myFile << "<!DOCTYPE html><html><head></head><body>";
	myFile << text;
	myFile << "<br><br><br>";
	myFile << "There were " << matches << " matches.<br>";
	myFile << "Brute force took " << BFtime << " microseconds.<br>";
	myFile << "Knuth-Morris Pratt took " << KMPtime << " microseconds.<br>";
	myFile << "Rabin Karp took " << RKtime << " microseconds.<br>";
	myFile << "</body></html>";
}

string getTextFromFile(string path){
	ifstream infile(path);
	stringstream textBuffer;
	textBuffer << infile.rdbuf();
	return textBuffer.str();
}

void testStringSearches(string txtF, string ptFile, string oFile){
	string text, pattern, origText;
	vector<int> timeToFindFirst;
	vector<int> timeToFindAll;
	vector<string> multiplePatterns = {"the", "because", "Potter", "and", "Harry", "Dursley", "sister", "good", "neighbor", "keeping", "child", "strange", "mysterious", "nothing" };

	chrono::duration<double, micro> timeMilli;

	text = getTextFromFile(txtF);
	pattern = getTextFromFile(ptFile);
	text.erase(remove(text.begin(), text.end(), '\n'), text.end());
	pattern.erase(remove(pattern.begin(), pattern.end(), '\n'), pattern.end());

	double BFtotalTime = 0.0;
	vector<int> BFall;
	for(int i=0; i < 100; i++){
		auto begin = chrono::steady_clock::now();
		BruteForce bf1(text, pattern);
		BFall = bf1.findAll();
		// bf1.findMultiple(multiplePatterns);
		auto end = chrono::steady_clock::now();
		timeMilli = end - begin;
		BFtotalTime += timeMilli.count();
	}
	BFtotalTime /= 100.0;

	double KMPtotalTime = 0.0;
	vector<int> KMPall;
	for(int i=0; i<100; i++){
		auto begin = chrono::steady_clock::now();
		KMPSearch KMPrun(text, pattern);
		KMPall = KMPrun.findAll();
		auto end = chrono::steady_clock::now();
		timeMilli = end - begin;
		KMPtotalTime += timeMilli.count();
	}
	KMPtotalTime /= 100.0;

	double RKtotalTime = 0.0;
	vector<int> RKall;
	for(int i=0; i<100; i++){
		auto begin = chrono::steady_clock::now();
		RabinKarp RKrun(text, pattern);
		RKall = RKrun.findAll();
		// RKrun.findMultiple(multiplePatterns);
		auto end = chrono::steady_clock::now();
		timeMilli = end - begin;
		RKtotalTime += timeMilli.count();
	}
	RKtotalTime /= 100.0;

	assert((BFall == KMPall) && (RKall == KMPall));
	for(int i = KMPall.size(); i >0; i--) //making it html friendly
		fixText(text, KMPall[i-1], pattern.size());

	printHTML(text, KMPall, oFile, KMPall.size(), BFtotalTime, KMPtotalTime, RKtotalTime);
}

int main(int argc, char **argv){
	if(argc != 4){
		cout << "./SearchComparisons <text file> <pattern file> <output file name>"<<endl;
	}
	testStringSearches(argv[1], argv[2], argv[3]);
	return 0;
}
