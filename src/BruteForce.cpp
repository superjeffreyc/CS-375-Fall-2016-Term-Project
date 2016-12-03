#include "BruteForce.h"

BruteForce::BruteForce(std::string text, std::string pattern) : 
									text(text), pattern(pattern){}

/*
	Naive brute force implementation for finding the next location of pattern
	Returns -1 as the "location" if the pattern was not found
*/
int BruteForce::search(){ 
	for(int i = 0; i < text.size(); i++){
		if(pattern[0] == text[i]){
			for(int j = 1; j < pattern.size(); j++){
				if(pattern[j] != text[i+j]) break;
				if(j == (pattern.size()-1)) return i;
			}
		}
	}
	return -1;
}
