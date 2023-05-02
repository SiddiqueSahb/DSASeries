/*
Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.length() == 0){
        output[0] = "";
        return 1;
    }

//if single digit letter
    if(input.length() == 1){
        //converting char to int
        int element = input[0]-'0';
        //mapping int val to respective character
        output[0] = 'a' + element - 1;
        return 1;
    }

    int first = input[0] - '0';
    char fchar = 'a' + first - 1;
    char secChar = '\0';
    string smallOutput1[1000];
    string smallOutput2[1000];
    int size1 = getCodes(input.substr(1), smallOutput1);
      int k = 0;
    //attaching 1st char mapping to output recieve by recursion
    for(int i = 0;i<size1;i++){
        output[k] = fchar + smallOutput1[i];
        k++;
    }
    int size2 = 0;
  
    if(input[1]!='\0'){
        // suppose input is 1123,we received output for 23 is [bc , w] so we checking whether we are having 2 digit input or not.
        //i.e 11 checking 2nd 1 of 11,if its exist then 1st one is already in int so multiply by 10 + converting 2nd character 
        // to int 
        int secElem = first * 10 + input[1] - '0';

        //checking whether int secElem lies between 10 and 26 inclusive
        //if its lies then finding mapping of the int
        if(secElem >= 10 && secElem <=26){
              // char secChar = 'a' + secElem - 1;
               secChar = 'a' + secElem - 1;
               size2 = getCodes(input.substr(2), smallOutput2);
        }
    }
//attaching 1st char mapping to output recieve by recursion for 2 digit characters
      for(int i = 0;i<size2;i++){
        output[k] = secChar + smallOutput2[i];
        k++;
    }

    return k;
}

