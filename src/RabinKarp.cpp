#include "RabinKarp.h"
#include <iostream>
#include <set>
using namespace std;

RabinKarp::RabinKarp(std::string text, std::string pattern) : text(text), pattern(pattern) {

	// So we know when to stop searching substrings
	lastSubstringIndex = text.length() - pattern.length();

	// Set up base value for calculating hashes
	primeNumber = 199;

	// Calculate value of most significant character: primeNumber ^ (patternLength-1)
	MSCfactor = calculateMSCFactor();
}

vector<vector<int>> RabinKarp::findMultiple(vector<string> patterns){
	vector<int> hashes;
	vector<vector<int>> multipleIndices;

	for (int i = 0; i < patterns.size(); i++) {
		hashes.push_back(calculateInitialHash(patterns[i]));
	}

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		int index = -1;
		for (int j = 0; j < hashes.size(); j++) {
			if (hashes[j] == textHash) {
				index = j;
				break;
			}
		}
		if (index != -1 && compareMultipleStrings(currentIndex, patterns[index])) {
			multipleIndices[index].push_back(currentIndex);
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex);
	}

	return multipleIndices;

}

vector<int> RabinKarp::findAll(){

	preprocessHashes();

	vector<int> indices;

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		if (patternHash == textHash && compareStrings(currentIndex)) {
			indices.push_back(currentIndex);
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex);
	}

	return indices;

}

int RabinKarp::search(){

	preprocessHashes();

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		if (patternHash == textHash && compareStrings(currentIndex)) {
			return currentIndex;
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex);
	}

	return -1;	// Could not find the pattern

}

// Calculate multiplier for most significant character
int RabinKarp::calculateMSCFactor() {
	int MSCfactor = 1;

	for (int i = 0; i < pattern.length()-1; i++) {
		MSCfactor = (MSCfactor*primeNumber);
	}

	return MSCfactor;
}

int RabinKarp::calculateInitialHash(string substring) {
	int hash = 0;

	for (int i = 0; i < pattern.length(); i++) {
		hash = (primeNumber*hash + substring[i]);
	}

	return hash;
}

// Check for identical strings
bool RabinKarp::compareStrings(int currentIndex) {
	for (int i = 0; i < pattern.length(); i++) {
		if (text[currentIndex+i] != pattern[i]) return false;
	}
	return true;
}

bool RabinKarp::compareMultipleStrings(int currentIndex, string pattern) {
	for (int i = 0; i < pattern.length(); i++) {
		if (text[currentIndex+i] != pattern[i]) return false;
	}
	return true;
}

// Rolling hash - remove most significant character and add next character. Runs in O(1)
void RabinKarp::calculateRollingHash(int currentIndex) {
	if (currentIndex < lastSubstringIndex) {
		textHash = primeNumber*(textHash - text[currentIndex]*MSCfactor);	// Remove most significant character
		textHash += text[currentIndex+pattern.length()];					// Add next character
	}
}

// Generate hash values for the pattern and the first text window
void RabinKarp::preprocessHashes() {
	patternHash = calculateInitialHash(pattern);
	textHash = calculateInitialHash(text);
}