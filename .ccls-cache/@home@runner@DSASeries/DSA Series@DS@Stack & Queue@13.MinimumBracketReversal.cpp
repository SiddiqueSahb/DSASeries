/*
Minimum bracket Reversal
Send Feedback
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

//APPROACH
/*
 I/P - {{}}{{{{
 I/P - {{}}}}{{
 I/P - }}{{ OR }}{{
 

  STEPS :
  In case of odd return false
  In case of even do following steps
  1.CASE WHEN INPUT - '{' - PUSH
  For  case - }
  2.CASE WHEN STACK IS NOT EMPTY AND TOP OF STACK = '{' DO POP
  3.CASE WHEN STACK IS NOT EMPTY AND TOP OF STACK IS NOT '{' DO PUSH
  AFTER ENTIRE INPUT IS TRAVERSED CHECK WHTHER STACK IS EMPTY OR NOT 
  POP 2 ELEMENT AND DO COMPARISON 
  IF SAME INCREMENT COUNT  ELSE INCREMENT COUNT BY 2
 
  }
  
 
*/


#include<stack>
#include<string>
int countBracketReversals(string input) {
	stack<char> s; 
	int count = 0;
	// Write your code here
	//Calculating the length of input if odd return -1 otherwise do calculation.
	int len = input.length();
    if( len % 2 == 0){
			for(int i = 0;i<input.length();i++){
				//if we get opening bracket push to stack
				if(input[i] == '{'){
					s.push(input[i]);
				}
				//if stack is not empty and top of stack is "{" do pop
				else {
                  if (!s.empty() && s.top() == '{') {
                      s.pop();
                    } else {
                       s.push(input[i]);
                     }
                }
          }
     while(!s.empty()){
		    	char c1 = s.top();
			    s.pop();
	   	   	char c2 = s.top();
	 	     	s.pop();
	     	if(c1 == c2){
	       		count++;
	       	}else{
		      	count+=2;
		      }
    	}
	return count;
	}
	else{
		
		return -1;

	}

}



////////////////////////////////////////////

#include<stack>
#include<string>
int countBracketReversals(string input) {
	stack<char> s; 
	int count = 0;
	// Write your code here
	//Calculating the length of input if odd return -1 otherwise do calculation.
	int len = input.length();
    if( len % 2 == 0){
			for(int i = 0;i<input.length();i++){
				//if we get opening bracket push to stack
				if(input[i] == '{'){
					s.push(input[i]);
				}
				//if stack is not empty and top of stack is "{" do pop
				else if (!s.empty() && s.top() == '{'){
					s.pop();
				}
				//if stack is not empty and top of stack is not "{" do push
				else if(!s.empty() && s.top() != '{'){
					s.push(input[i]);
				}
				//IF STACK IS EMPTY AND INPUT IS } DO PUSH
				else if(s.empty() && input[i] == '}'){
					s.push(input[i]);
				}		
	}
  // 
	if(!s.empty()){
			while(!s.empty()){
			char c1 = s.top();
			s.pop();
			char c2 = s.top();
			s.pop();
		if(c1 == c2){
			count++;
		}else{
			count+=2;
		}
	}
	
	}
	return count;
	}
	else{
		
		return -1;

	}
}


