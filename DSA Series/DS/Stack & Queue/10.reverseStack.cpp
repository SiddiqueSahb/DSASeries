/*
Reverse a Stack
Send Feedback
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
For Example:
Alt txt

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.
Output Format:
The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.
Constraints:
1 <= N <= 10^3
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 
Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.
Sample Input 2:
5
2 8 15 1 10
Sample Output 2:
2 8 15 1 10
*/

//Approach
/*
1. there is input stack and take helper stack to reverse the input stack
2.Reverse stack using recursion then again reverse using helper stack
3.initially Remove top element and call recursion on n-1 elements in stack.
4.Now we get reversed stack.
5.From reversed stack pop each element and push to helper stack.
6.Element that was removed initialy is pushed to input stack and then again pop each element and push to input stack.
7.Finally we get reversed stack.
*/


#include<stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    //base case
    if(input.size() <= 1){
        return ;
    }

    //Get top element from the stack , remove it and call recursion for remaining elements .
    //recursion gives us back reversed element
    //extra stack is a helper stack
    //remove reversed element from the stack untill input stack is empty and push it to extra (stack)
    //When the input stack becomes empty ,push the removed element to input stack, and then pop every element from the extra stack 
    //untils its empty and push it to input stack.
    //final o/p will be reversed stack.
    int data = input.top();
    input.pop();
    reverseStack(input,extra);

  // From reversed stack pop each element and push to helper stack.
    while(!input.empty()){
        int temp = input.top();
        input.pop();
        extra.push(temp);
    }
  //Element that was removed initialy is pushed to input stack
     input.push(data);

  //then pop every element from the extra stack  untils its empty and push it to input stack.
     while(!extra.empty()){
         int x = extra.top();
         extra.pop();
         input.push(x);
     }

}