#include "rabinkarp.h"

using namespace std;

void rabinKarpSearch(string pattern, string text) {
	
	int patternLength = pattern.length();
	int textLength = text.length();
    int numSubstrings = textLength - patternLength;
    
    int patternHash = 0;
    int textHash = 0;
    
    int primeNumber = 199;      // Base value for calculating hashes
    int MSCfactor = 1;          // Multiplier for most significant character    
    int totalMatches = 0;
    
    // Calculate value of most significant character: primeNumber ^ (patternLength-1)
    for (int i = 0; i < patternLength-1; i++) {
        MSCfactor = (MSCfactor*primeNumber);
    }
        
    // Generate hash values for the pattern and the first text window
    for (int i = 0; i < patternLength; i++) {
        patternHash = (primeNumber*patternHash + pattern[i]);
        textHash = (primeNumber*textHash + text[i]);
    }
    
    // Slide the text window and check for a matching pattern
    for (int currentIndex = 0; currentIndex <= numSubstrings; currentIndex++) {

        // Compare hashes
        if (patternHash == textHash) {
            
            // Verify that they are the same string
            int i;
            for (i = 0; i < patternLength; i++) {
                if (text[currentIndex+i] != pattern[i]) break;
            }

            // If the index has reached the end of the pattern, it must be a match
            if (i == patternLength) {
                printf("Pattern found at index %d.\n", currentIndex);
                totalMatches++;
            }
        }

        // Calculate rolling hash - remove most significant character and add next character
        if (currentIndex < numSubstrings) {
            textHash = (primeNumber*(textHash - text[currentIndex]*MSCfactor) + text[currentIndex+patternLength]);
        }
    }
    
    cout << "Total Matches: " << totalMatches << endl;
}