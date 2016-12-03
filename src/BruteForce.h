#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <string>

#include "StringSearch.h"

class BruteForce : public StringSearch {
	std::string text;
	std::string pattern;

public:
	BruteForce(std::string, std::string);
	int search();
};

#endif
