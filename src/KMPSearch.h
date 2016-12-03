#ifndef KMP_SEARCH_H
#define KMP_SEARCH_H

#include "StringSearch.h"

class KMPSearch : public StringSearch {
	std::string text;
	std::string pattern;

public:
	KMPSearch(std::string, std::string);
	int search();
};

#endif
