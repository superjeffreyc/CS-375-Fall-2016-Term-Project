#include "KMPSearch.h"

KMPSearch::KMPSearch(std::string textP, std::string patternP){
	text = textP;
	pattern = patternP;
	pSize = pattern.size(); //easier to type vars
	tSize = text.size();
	suffixArr.resize(patternP.size());
	//suffixArr(patternP.size()); //auto initialize to 0

	computeSuffixArr();
}

//easy printing function
void KMPSearch::printSuffixArray(){
	std::cout << "~~~Printing suffix arr~~~"<<std::endl;
	for(int i = 0; i < pSize; i++)
		std::cout<<suffixArr[i]<< " ";
	std::cout << "\n~~~Done Printing~~~"<<std::endl;
}

//computing prefix-suffix array for KMP Search
void KMPSearch::computeSuffixArr(){
	int j=0;
	for(int i=1; i<pSize;i++){
		if(pattern[i] == pattern[j])
			suffixArr[i] = ++j;
		else if(j != 0){ //if not at beginning of pattern - use prefix-suffix
			i--; 	//array to move locations and prevent loop increment
			j=suffixArr[j-1];
		}//else increment i and move on
	}
	//printSuffixArray();
}

//actual KMP algorithm after preSuff array created
bool KMPSearch::KMPSearchHelper(int &tIndex){
		int pIndex = 0; //position in pattern
		while((tIndex < tSize) && (pIndex < pSize)){ //if at the end - ret
			if(text[tIndex] == pattern[pIndex]){
				tIndex++;
				pIndex++;
			}else if(pIndex != 0){ //go to Arr for quicker increments
				pIndex = suffixArr[pIndex-1];
			}else{	//move on with text - prefSuffArr won't help
				tIndex++;
			}
		}
		return (pIndex == pSize); //did we find a location?
}								//it's stored in tIndex

//finds all locations of pattern
std::vector<int> KMPSearch::findAll(){
	std::vector<int> locations;
	int tIndex = 0;
	bool found = true;
	while(found){ //find all locations
		found = KMPSearchHelper(tIndex);
		if(found)
			locations.push_back(tIndex - pSize); // fixing index
	}
	return locations;
}

//finds first location of pattern
int KMPSearch::search(){
	int tIndex = 0;
	bool found = KMPSearchHelper(tIndex);
	if(found)
		return (tIndex - pSize);
	else
		return -1;
}

std::vector<std::vector<int>> KMPSearch::findMultiple(std::vector<std::string> patterns){
	std::vector<std::vector<int>> ret;
	for(int i =0; i < patterns.size(); i++){
		pattern = patterns[i];
		suffixArr.clear();
		pSize = patterns[i].size();

		suffixArr.resize(patterns[i].size());//suffixArr(patterns[i]);
		computeSuffixArr();
		ret.push_back(findAll());
	}

	return ret;
}

//cleaning up prefix suffix arr
/*KMPSearch::~KMPSearch(){
	delete[] suffixArr;
}*/

