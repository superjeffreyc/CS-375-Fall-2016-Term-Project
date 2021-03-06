#include "BruteForce.h"

BruteForce::BruteForce(std::string text, std::string pattern) :
									text(text), pattern(pattern){}

// Naive brute force implementation for finding the next location of pattern
bool BruteForce::searchHelper(int &tIndex){
	for(;tIndex < text.size(); tIndex++){
		for(int j = 0; j < pattern.size(); j++){
			if(pattern[j] != text[tIndex+j])
				break;
			if(j == (pattern.size()-1)){ //double check this logic
				tIndex++;			//was causing a nasty bug earlier
				return true;
			}
		}
	}
	return false;
}

int BruteForce::search(){
	int tIndex = 0;
	bool found = searchHelper(tIndex);
	if(found)
		return (tIndex-1);
	else
		return -1;
}

std::vector<std::vector<int>> BruteForce::findMultiple(std::vector<std::string> patterns) {
	std::vector<std::vector<int>> multipleIndices;
	for (std::string s : patterns) {
		pattern = s;
		std::vector<int> indices = findAll();
		multipleIndices.push_back(indices);
	}

	return multipleIndices;
}

std::vector<int> BruteForce::findAll(){
	std::vector<int> locations;
	int tIndex = 0;
	bool found = true;
	while(found){
		found = searchHelper(tIndex);
		if(found)
			locations.push_back((tIndex-1));
	}
	return locations;
}
