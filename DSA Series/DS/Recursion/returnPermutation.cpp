/*

Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/

	//base case
	if(input.length() == 0){
		output[0] = "";
		return 1;
	}

	string smallOutput[10000];
	int smallOutputSize = returnPermutations(input.substr(1), smallOutput);
	int k = 0; // index for output array
	//traversing the smallOutput array to pick up a string in that i.e dg
	for(int i = 0;i<smallOutputSize;i++){
		for(int j = 0;j<smallOutput[i].length()+1;j++){
			//selecting element from smallOutput array and the traversing that string and attaching character at every possible 
      // places. suppose we got output bc and attaching a to every possible places in bc. _b_c_ (so traversing 3 times - string length + 1)
			//then storing to ouput array
			output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j); //element after attaching character
      //attaching a to middle of bc i.e - b _ c;
      //so substring from o to i + character + substring from j
		}
	}
	return k;
}
