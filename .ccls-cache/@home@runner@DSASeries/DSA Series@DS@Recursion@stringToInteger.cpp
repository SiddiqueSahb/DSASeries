/* 
String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567

*/


#include <string.h>
#include<math.h>
int stringToNumber(char input[]) {
    // Write your code here
     int len = strlen(input);
    if(len == 0){
        return 0;
    }
  //ascii value of '0' is 48 and '1' is 49 so 49-48 = 1, '2'(char) = 50 so 50 - 48 = 2(int)
    int b = input[0] - '0';
    int val = b * pow(10,len-1); 
    return val + stringToNumber(input+1);
    
}