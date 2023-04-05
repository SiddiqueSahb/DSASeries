/*
Sum of digits (recursive)
Send Feedback
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9
*/

int sumOfDigits(int n) {
    // Write your code here
int d,sum;
//base case
if(n==0){
    return 0;
}
d = n%10;
int ans = sumOfDigits(n/10);
sum = d + ans;
return sum;
}