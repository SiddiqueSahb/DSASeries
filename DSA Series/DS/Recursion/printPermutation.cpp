/*
Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

void print(string input, string output) {
    // BASE CASE
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.size(); i++) {
        // RECURSION CALL
        // 0 to i-1 tak include + i+1 se end tak include karega string ka
        //Dry run for this to get insight of how loop works here
        print(input.substr(0, i)+ input.substr(i + 1), output + input[i]);
    }
}

void printPermutations(string input) {
    string output = "";
    print(input, output);
}