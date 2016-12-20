# CS-375-Fall-2016-Term-Project
String Searching Algorithms
By Jeffrey Chan and Anson Varughese

## Algorithms
 BruteForce Algorithm
- No pre-processing
- For each substring, compare the first character to the pattern's first character.
	- If there is a match, continue to verify that all characters match.
	- Otherwise, move on to the next substring.
- Average time complexity: O(nm)
- Worst case time complexity: O(nm)

Rabin Karp Algorithm
- Pre-process the pattern and first text window by calculating their hashes in O(m)
- Use a rolling hash to compare each substring to the pattern hash in O(n)
	- If the hashes match, verify that all the characters match.
- Average time complexity: O(n+m)
- Worst case time complexity: O(nm)

Knuth Morris Pratt Algorithm
- Pre-process the pattern by creating a prefix-suffix array in O(m)
- Use the prefix-suffix array to skip characters in the text when searching for the pattern. 
- Best/Average/Worst time complexity: O(n+m)
- Space Complexity: O(m)

## Things to Finish
- change highlighting color for each find multiple word
- finish ppt KMP

## How To Run
```sh
	$ make
	$ ./SearchComparisons ../test/t4Text.txt ../test/t4Pattern.txt output.html multiple
	$ firefox output.html & 
```
or 
```sh
	$ make runMultiple
	firefox output.html &
```

