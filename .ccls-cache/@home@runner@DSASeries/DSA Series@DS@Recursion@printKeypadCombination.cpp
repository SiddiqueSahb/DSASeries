/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

void print_subs(int input, string output,string mapping[]) {
	if (input == 0) {
		cout << output << endl;
		return;
	}
	int d = input%10;
	int n = input/10;
	string digit = mapping[d];
	for(int i=0;i<digit.length();i++){
	   	print_subs(n, digit[i]+output,mapping);
	}
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
	string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
	print_subs(num, output,mapping);
}
