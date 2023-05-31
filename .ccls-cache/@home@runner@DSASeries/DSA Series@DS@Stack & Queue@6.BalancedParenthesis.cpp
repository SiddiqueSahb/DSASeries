/*
Code : Balanced Parenthesis
Send Feedback
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
*/

//Approach
/*
1.Initially check if stack is empty then push element otherwise
2.Check if top of stack and input element are same then push otherwise pop
3.Do this process till the end of the string.
4.if stack is empty then parenthesis is balanced else its not.
*/

#include<stack>
#include<string>
bool isBalanced(string expression) 
{
    // Write your code here
  //creating stack s
    stack<int> s;
    //traversing each character in a string
    for(int i = 0;i<expression.length();i++){
        //initially checking if stack is empty then pushing the element to stack;
         if(s.empty()){
         s.push(expression[0]);
    }
    //if stack is not empty then check its top element and input character
    //if its same then push the element otherwise pop the element
       else if(expression[i] == '(' && s.top() == '('){
            s.push(expression[i]);
        }else if (expression[i] == ')' && s.top() == ')'){
            s.push(expression[i]);
        }else if(s.top() == '(' && expression[i] == ')'){
            s.pop();
        }
    }
    //after traversing whole string check whether stack is empty or not
    //if stack is empty then parenthesis is balanced otherwise not
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}
