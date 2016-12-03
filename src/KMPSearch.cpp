#include "KMPSearch.h"

KMPSearch::KMPSearch(std::string text, std::string pattern) {
	text(text);
	pattern(pattern);
	pSize = pattern.size();
	suffixArr = new int[pSize];
}

KMPSearch::computeSuffixArr(){
	suffixArr[0] = 0;
	int j = 0;
	int i = 1;

	while(i < pSize){
		if(pattern[i] == pattern[j]){
			suffixArr[i] = j+1; //++j?
			i++;
			j++;
		}else{
			if(j != 0){
				j = suffixArr[j-1];
			}else{
				suffixArr[i] = 0;
				i++;
			}
		}
	}
}

int KMPSearch::search(){
	computeSuffixArr();	
	
	return 0;
}


