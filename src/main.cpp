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

void printHTML(string text, vector<int> locations){ //print out time as well
	ofstream myFile("../test/t3Output.html");
	myFile << "<!DOCTYPE html><html><head></head><body>";
	myFile << text;
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
void testStringSearches(){
	string text;
	string pattern;
	vector<int> timeToFindFirst;
	vector<int> timeToFindAll;
	
	text = getTextFromFile("../test/t3Text.txt");
	pattern = getTextFromFile("../test/t3Pattern.txt");
	//getting rid of newline char at the end
	text.erase(remove(text.begin(), text.end(), '\n'), text.end());
	pattern.erase(remove(pattern.begin(), pattern.end(), '\n'), pattern.end());

	auto begin = chrono::steady_clock::now();
	BruteForce bf1(text, pattern);
	int BFfirst = bf1.search();
	vector<int> BFall = bf1.findAll();
	auto end = chrono::steady_clock::now();
	chrono::duration<double, micro> timeMilli = end - begin;
	cout<<"time diff in microsecs is " << timeMilli.count()<<endl;

	KMPSearch kmp1(text, pattern);
	int KMPfirst = kmp1.search();
	vector<int> KMPall = kmp1.findAll();

	assert((BFfirst == KMPfirst) && (BFall == KMPall));
	cout<<"pattern is of KMPall is "<<KMPall.size()<<endl;
	for(int i = KMPall.size(); i >0; i--) //making it html friendly
		fixText(text, KMPall[i-1], pattern.size());
	
	printHTML(text, KMPall);
	/*
	RabinKarp rk(text, pattern);
	ret = rk.search();
	cout << "Rabin-Karp: ";
	if (ret == -1) cout << "Couldn't find pattern in text!" << endl;
	else printFoundText(text, ret, pattern.size());
	*/
}

int main(){
	string text;
	string pattern;
	testStringSearches();

	return 0;
}
