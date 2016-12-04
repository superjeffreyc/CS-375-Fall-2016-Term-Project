#ifndef KMP_SEARCH_H
#define KMP_SEARCH_H

#include <string>
#include <iostream>
#include <vector>

#include "StringSearch.h"

class KMPSearch : public StringSearch {
	std::string text;
	std::string pattern;
	int pSize;
	int tSize;
	int *suffixArr; 

public:
	KMPSearch(std::string textP, std::string patternP);

	void computeSuffixArr();
	bool KMPSearchHelper(int &tIndex);
	int search();
	std::vector<int> findAll();
	void printSuffixArray();
	
	~KMPSearch();
};

#endif
