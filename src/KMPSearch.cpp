#include "KMPSearch.h"

KMPSearch::KMPSearch(std::string textP, std::string patternP){
	text = textP;
	pattern = patternP;
	pSize = pattern.size();
	tSize = text.size();
	suffixArr = new int[pSize](); //auto initialize to 0

	computeSuffixArr();
}

void KMPSearch::printSuffixArray(){
	std::cout << "~~~Printing suffix arr~~~"<<std::endl;
	for(int i = 0; i < pSize; i++)
		std::cout<<suffixArr[i]<< " ";
	std::cout << "\nDone"<<std::endl;
}

void KMPSearch::computeSuffixArr(){
	int j=0;
	for(int i=1; i<pSize;i++){
		if(pattern[i] == pattern[j])
			suffixArr[i] = ++j;
		else if(j != 0){
			i--; // preventing for-loop increment
			j=suffixArr[j-1];
		}
	}
	//printSuffixArray();

	/*while(i < pSize){
		if(pattern[i] == pattern[j]){
			suffixArr[i] = ++j;
			i++;
		}else{
			if(j != 0){
				j = suffixArr[j-1];
			}else{
				suffixArr[i] = 0;
				i++;
			}
		}
	}*/
	
}

bool KMPSearch::KMPSearchHelper(int &tIndex){
		int pIndex = 0; //position in pattern
		while((tIndex < tSize) && (pIndex < pSize)){
			if(text[tIndex] == pattern[pIndex]){
				tIndex++;
				pIndex++;
			}else if(pIndex != 0){
				pIndex = suffixArr[pIndex-1];
			}else{
				tIndex++;
			}
		}
		return (pIndex == pSize);
}

std::vector<int> KMPSearch::findAll(){
	std::vector<int> locations;
	int tIndex = 0;
	bool found = true;
	while(found){
		found = KMPSearchHelper(tIndex);
		if(found)
			locations.push_back(tIndex - pSize);
	}
	return locations;
}

int KMPSearch::search(){
	int tIndex = 0;
	bool found = KMPSearchHelper(tIndex);
	if(found) 
		return (tIndex - pSize);
	else
		return -1;
}

KMPSearch::~KMPSearch(){
	delete[] suffixArr;
}

