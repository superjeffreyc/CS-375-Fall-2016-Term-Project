#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <string>
#include <vector>
#include <iostream>

#include "StringSearch.h"

class BruteForce : public StringSearch {
	std::string text;
	std::string pattern;

public:
	BruteForce(std::string, std::string);
	bool searchHelper(int &tIndex);
	int search();
	std::vector<int> findAll();
	std::vector<std::vector<int>> findMultiple(std::vector<std::string>);

};

#endif
