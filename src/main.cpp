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

//indices start from 1
//should it handle lowercase?
void testStringSearches(string txtF, string ptFile, string oFile){
	string text, pattern, origText;
	vector<int> timeToFindFirst;
	vector<int> timeToFindAll;
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
		auto end = chrono::steady_clock::now();
		timeMilli = end - begin;
		BFtotalTime += timeMILLi;
	}

	double KMPtotalTime = 0.0
	vector<int> KMPall;
	for(int i=0; i<100; i++){
		auto begin = chrono::steady_clock::now();
		BruteForce KMPrun(text, pattern);
		KMPall = KMPrun.findAll();
		auto end = chrono::steady_clock::now();
		timeMilli = end - begin;
		KMPtotalTime += timeMILLi;
	}

	assert((BFall == KMPall));
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

	return 0;
}
