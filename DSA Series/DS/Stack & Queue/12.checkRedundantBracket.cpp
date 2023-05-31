/*
Check redundant brackets
Send Feedback
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Note:
You are not required to print the expected result. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false
*/

//APPROACH
/*
1.if any opening bracket comes or some operator/operand comes continue to push to the stack untill we get closing bracket.
2.Once closing bracket arrives , pop each element  and check each if its operator untill closing bracket arrives.
3.If we get operator between opening and closing bracket then bracket is not redundant other wise bracket is redundant

*/


#include <stack>
#include <string>

bool checkRedundantBrackets(string expression) {
    stack<char> s;
    int len = expression.length();
    int i = 0;
    
    while (i < len) {
        if (expression[i] == ')') {
            // If a closing bracket is encountered, check for redundancy
            bool foundOperator = false;
            
            // Pop elements until an opening bracket is found
            while (!s.empty() && s.top() != '(') {
                char ch = s.top();
                s.pop();
                // Check if an operator is present
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                    foundOperator = true;
                }
            }
            
            // If no operator is found between brackets, it is redundant
            if (!foundOperator) {
                return true;
            }
            
            s.pop(); // Pop the opening bracket
        } 
        else {
            // Push other characters onto the stack
            s.push(expression[i]);
        }
        
        i++;
    }
    
    // No redundant brackets found
    return false;
}
