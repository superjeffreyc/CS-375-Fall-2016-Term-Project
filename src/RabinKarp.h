#ifndef RABINKARP_SEARCH_H
#define RABINKARP_SEARCH_H

#include "StringSearch.h"

class RabinKarp : public StringSearch {
	std::string text;
	std::string pattern;
	int primeNumber;
	int MSCfactor;

public:
	RabinKarp(std::string, std::string);
	int search();

private:
	int calculateMSCFactor();
	int calculateInitialHash(std::string substring);
	bool compareStrings(int currentIndex);
	int calculateRollingHash(int textHash, int currentIndex, int lastSubstringIndex);
	void hashPreparations();
};

#endif
