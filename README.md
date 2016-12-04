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
- split main file into multiple functions with testing and timing seperated
- integrate RK in testing
- create more test cases
- have html file show time for each algo as well
- litter code with more comments? (probably not needed though)
- change highlighting color and/or method
- change up html doc to make it better presentation?

## How To Run
```sh
	$ make
	$ ./SearchComparisons
	$ cd ../test/
	$ firefox t3Output.html &
```
Change up the test files to see different ones in html with highlight	

