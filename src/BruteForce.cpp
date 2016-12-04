#include "BruteForce.h"

BruteForce::BruteForce(std::string text, std::string pattern) : 
									text(text), pattern(pattern){}


// Naive brute force implementation for finding the next location of pattern

bool BruteForce::searchHelper(int &tIndex){
	for(;tIndex < text.size(); tIndex++){
		if(pattern[0] == text[tIndex]){
			for(int j = 1; j < pattern.size(); j++){
				if(pattern[j] != text[tIndex+j]) break;
				if(j == (pattern.size()-1)) return true;
			}
		}
	}
	return false;
}

int BruteForce::search(){ 
	int tIndex = 0;
	bool found = searchHelper(tIndex);
	if(found)
		return tIndex;
	else
		return -1;
}

std::vector<int> BruteForce::findAll(){
	std::vector<int> locations;
	int tIndex = 0;
	bool found = true;
	while(found){
		found = searchHelper(tIndex);
		if(found)
			locations.push_back(tIndex);
	}
	return locations;
}
