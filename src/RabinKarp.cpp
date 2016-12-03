#include "RabinKarp.h"
#include <iostream>

using namespace std;

RabinKarp::RabinKarp(std::string text, std::string pattern) : text(text), pattern(pattern) {

	// So we know when to stop searching substrings
	lastSubstringIndex = text.length() - pattern.length();

	// Set up base value for calculating hashes
	primeNumber = 199;

	// Calculate value of most significant character: primeNumber ^ (patternLength-1)
	MSCfactor = calculateMSCFactor();

	// Generate hash values for the pattern and the first text window
	patternHash = calculateInitialHash(pattern);
	textHash = calculateInitialHash(text);
}

int RabinKarp::search(){

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		if (patternHash == textHash && compareStrings(currentIndex)) {
			return currentIndex;
		}

		// Calculate rolling hash - remove most significant character and add next character
		textHash = calculateRollingHash(textHash, currentIndex, lastSubstringIndex);
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

// Rolling hash - remove most significant character and add next character. Runs in O(1)
int RabinKarp::calculateRollingHash(int textHash, int currentIndex, int lastSubstringIndex) {
	if (currentIndex < lastSubstringIndex) {
		textHash = primeNumber*(textHash - text[currentIndex]*MSCfactor);	// Remove most significant character
		textHash += text[currentIndex+pattern.length()];					// Add next character
	}
	return textHash;	// No more substrings left
}