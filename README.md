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
- (explanation)

## Things to Finish
- create more test cases (backpack for KMP) (harry potter for random) (RK - )
- change highlighting color for each find multiple word
- make command line arg to take another flag for running multiple patterns
- finish ppt KMP

## How To Run
```sh
	$ make
	$ ./SearchComparisons ../test/t4Text.txt ../test/t4Pattern.txt output.html
	$ firefox output.html & 
```
or 
```sh
	$ make run
	firefox output.html &
```

