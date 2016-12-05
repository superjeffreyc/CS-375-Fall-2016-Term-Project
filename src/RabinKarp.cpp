#include "RabinKarp.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

RabinKarp::RabinKarp(std::string text, std::string pattern) : text(text), pattern(pattern) {

	// Set up base value for calculating hashes
	primeNumber = 199;

	// Calculate value of most significant character: primeNumber ^ (patternLength-1)
	MSCfactor = calculateMSCFactor();
}

vector<vector<int>> RabinKarp::findMultiple(vector<string> patterns){
	unordered_multimap<int, string> hashToStringMap;
	unordered_multimap<string, int> stringToIndexMap;
	int minLength = getMinLength(patterns);
	textHash = calculateInitialHash(text.substr(0, minLength));
	lastSubstringIndex = text.length() - minLength;

	vector<vector<int>> multipleIndices;
	multipleIndices.reserve(patterns.size());

	for (int i = 0; i < patterns.size(); i++) {
		vector<int> tempVector;
		tempVector.reserve(10);
		multipleIndices.push_back(tempVector);
	}

	// Initial hashes
	for (int i = 0; i < patterns.size(); i++) {
		hashToStringMap.insert(
			{ calculateInitialHash(patterns[i]), patterns[i] }
		);

		// For figuring out what index to put a matching pattern to
		stringToIndexMap.insert(
			{ patterns[i], i }
		);
	}

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Get all strings that map to this hash
		auto range = hashToStringMap.equal_range(textHash);

		for (auto it = range.first; it != range.second; it++) {
			if (compareStrings(currentIndex, it->second)) {
				auto indexIter = stringToIndexMap.find(it->second);
				multipleIndices[indexIter->second].push_back(currentIndex);
				break;
			}
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex, minLength);

	}

	return multipleIndices;

}

vector<int> RabinKarp::findAll(){

	preprocessHashes();

	vector<int> indices;

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		if (patternHash == textHash && compareStrings(currentIndex, pattern)) {
			indices.push_back(currentIndex);
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex, pattern.length());
	}

	return indices;

}

int RabinKarp::search(){

	preprocessHashes();

	// Slide the text window and check for a matching pattern
	for (int currentIndex = 0; currentIndex <= lastSubstringIndex; currentIndex++) {

		// Compare hashes and verify that they are the same string
		if (patternHash == textHash && compareStrings(currentIndex, pattern)) {
			return currentIndex;
		}

		// Calculate rolling hash - remove most significant character (at currentIndex) and add next character after the window
		calculateRollingHash(currentIndex, pattern.length());
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

	for (int i = 0; i < substring.length(); i++) {
		hash = (primeNumber*hash + substring[i]);
	}

	return hash;
}

// Compare s and text window for identical strings
bool RabinKarp::compareStrings(int currentIndex, string s) {

	if (currentIndex + s.length() > text.length()) return false;		// Already reached the end

	for (int i = 0; i < s.length(); i++) {
		if (text[currentIndex+i] != s[i]) return false;
	}
	return true;
}

// Rolling hash - remove most significant character and add next character. Runs in O(1)
void RabinKarp::calculateRollingHash(int currentIndex, int patternLength) {
	if (currentIndex < lastSubstringIndex) {
		textHash = primeNumber*(textHash - text[currentIndex]*MSCfactor);	// Remove most significant character
		textHash += text[currentIndex+patternLength];						// Add next character
	}
}

// Generate hash values for the pattern and the first text window
void RabinKarp::preprocessHashes() {
	// So we know when to stop searching substrings
	lastSubstringIndex = text.length() - pattern.length();

	patternHash = calculateInitialHash(pattern);
	textHash = calculateInitialHash(text.substr(0, pattern.length()));
}

int RabinKarp::getMinLength(std::vector<std::string> patterns) {
	int min = patterns[0].length();

	for (int i = 1; i < patterns.size(); i++) {
		if (patterns[i].length() < min) min = patterns[i].length();
	}
}