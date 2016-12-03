#include "KMPSearch.h"

KMPSearch::KMPSearch(std::string text, std::string pattern) : 
							text(text), pattern(pattern) {}

int KMPSearch::search(){
	handlePP();	
	
	return 0;
}


