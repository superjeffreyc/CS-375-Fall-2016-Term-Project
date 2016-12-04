#ifndef RABINKARP_SEARCH_H
#define RABINKARP_SEARCH_H

#include "StringSearch.h"

class RabinKarp : public StringSearch {
	std::string text;
	std::string pattern;

	int primeNumber;			// Base multiplier for each character
	int MSCfactor;				// Most significant character multiplier
	int lastSubstringIndex;

	int patternHash;
	int textHash;

public:
	RabinKarp(std::string, std::string);
	int search();
	std::vector<int> findAll();

private:
	int calculateMSCFactor();
	int calculateInitialHash(std::string substring);
	bool compareStrings(int currentIndex);
	void calculateRollingHash(int currentIndex);
};

#endif
