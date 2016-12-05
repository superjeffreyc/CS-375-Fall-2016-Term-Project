#ifndef RABINKARP_SEARCH_H
#define RABINKARP_SEARCH_H

#include "StringSearch.h"

class RabinKarp : public StringSearch {
	std::string text;
	std::string pattern;

	int primeNumber;			// Base multiplier for each character
	int MSCfactor;				// Most significant character multiplier
	int lastSubstringIndex;

	int patternHash = 0;
	int textHash = 0;

public:
	RabinKarp(std::string, std::string);
	int search();
	std::vector<int> findAll();
	std::vector<std::vector<int>> findMultiple(std::vector<std::string>);

private:
	int calculateMSCFactor();
	int calculateInitialHash(std::string substring);
	bool compareStrings(int currentIndex, std::string pattern);
	void calculateRollingHash(int currentIndex, int patternLength);
	void preprocessHashes();
	int getMinLength(std::vector<std::string>);
};

#endif
