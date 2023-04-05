/*
Check Palindrome (recursive)
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include<cstring>
bool helper(char input[],int s,int e){
    if(s>e){
        return true;
    }
        s++;
        e--;
     if(input[s] == input[e]){
        helper(input, s, e);
    }else{
        return false;
    }
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int len = strlen(input);
    int s = 0;
    int e = len-1;

    if(input[s] != input[e]){
        return false;
    }
    else{
        return helper(input,s,e);
    }

}


//after editing
#include<cstring>
bool helper(char input[],int s,int e){

    if(input[0]=='\0' || input[1] == '\0'){
        return true;
    }

    if(s>=e){
        return true;
    }

     if(input[s] == input[e]){
        return helper(input, s+1, e-1);
    }else{
        return false;
    }
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int len = strlen(input);
    int s = 0;
    int e = len-1;

    if(input[s] != input[e]){
        return false;
    }
    else{
        return helper(input,s,e);
    }

}


