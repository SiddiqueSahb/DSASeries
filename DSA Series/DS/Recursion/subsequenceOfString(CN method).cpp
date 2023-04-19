#include <iostream>
using namespace std;

int subs(string input, string output[]) {
  //if input is empty then output is empty and return 
	if (input.empty()) {
		output[0] = "";
		return 1;
	}
  //if input is abc then call recursion for bc so index giving 1
	string smallString = input.substr(1);
  //calling recursion so we receive an output and we add given input strings 1st character for that output.
	int smallOutputSize = subs(smallString, output);
  //traversing each output and adding character while returning from the recursive call.
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
  //after adding string we doubling the size .After getting output as " " then adding a + " " = a and then returning the 
 // updated size of output.
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}
