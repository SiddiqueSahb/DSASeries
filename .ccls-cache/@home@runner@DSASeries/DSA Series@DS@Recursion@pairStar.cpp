/*
Pair Star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

// Change in the given string itself. So no need to return or print the changed string.
//For reference check replacPi.cpp

#include<string.h>
void pairStar(char input[]) {
    // Write your code here
    int len = strlen(input);
	if(len<=1){
		return;
	}

	pairStar(input+1);

  //checking whether adjacents are equal or not
	if(input[0] == input[1]){
		int count = 0;
		int i = 0;

    //traversing to get the count of element
		while(input[i]!='\0'){
			count++;
			i++;
		}

    //shifting part is very imp
		for(int i = count + 1;i>=1;i--){
			input[i+1] = input[i];
		}
        input[1] = '*'; 
	}

	else {
		return;
	}
}