/*
Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
  */



// Change in the given string itself. So no need to return or print anything
#include<string.h>
void replacePi(char input[]) {
	// Write your code here
	int len = strlen(input);
	if(len<=1){
		return;
	}
	replacePi(input+1);

	if(input[0] == 'p' && input[1]=='i'){
		int count = 0;
		int i = 0;

		//traversing the input array to get the count of element then we will know that count +1 is '\0'
		//p i \0. ->. at index count + 1 = 1+1 = 2 is '\0' is present
		while(input[i]!='\0'){
			count++;
			i++;
		}
  
	//here were shifting element by two i.e pi \0 making p i _ _'\0
	//why? i>=2 bcz  we only require two extra space then we can change the content of 4 elements in array.
	//initially shifting null terminated character i.e 1st shifting '\0 
		for(int i = count + 1;i>=2;i--){
			input[i+2] = input[i];
		}

		   input[0] = '3';  //p is replaced with 3
        	input[1] = '.'; //i is replaced with .
  		  input[2] = '1'; 
  		  input[3] = '4'; 
	}
	else {
		return;
	}

}


