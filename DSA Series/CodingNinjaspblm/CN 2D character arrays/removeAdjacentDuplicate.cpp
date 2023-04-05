// Online C++ compiler to run C++ program online
/*
Remove Consecutive Duplicates
Send Feedback
For a given string(str), remove all the consecutive duplicate characters.
Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"

 Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
The only line of output prints the updated string.


Sample Input 1:
aabccbaa
Sample Output 1:
abcba
Sample Input 2:
xxyyzxx
Sample Output 2:
xyzx

*/

//********LOGIC************
//yaha pe loop 1 se start karo aur ek char banao usme 0th index element ko put karo.
//loop wale element ko  0th index element se compare karo, if same hai toh aage badho aur nhi same hai toh ith element ko put karo aur usko lastChar banado;


#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int main() {
    char input[100] = "aabbbcc";
    cout<<"Before removing duplicates :- "<<input<<endl;
    int j = 1;
    char lastChar = input[0];
    for(int i = 1;input[i]!='\0';i++){
        if(input[i] != lastChar){
            input[j] = input[i];
            lastChar = input[i];
            j++;
        }
    }
    input[j] = '\0';
cout<<"After removing duplicates:- "<<input<<endl;
}