/*
Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
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

void print(string input,string output){
    //base case
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }

//Mistake - checking for length 1 and here output was replaced by input
    // if( input.length() == 1){
    //      //converting char to int
    //     int element = input[0]-'0';
    //     //mapping int val to respective character
    //     output[0] = 'a' + element - 1;
    //     cout<<output<<endl;
    //     return;
    // }

    int first  = input[0] - '0';
    char secChar = '\0';
    char fchar = 'a' + first - 1;
    print(input.substr(1), output+fchar);
    if(input[1]!='\0'){
           int secElem = first * 10 + input[1] - '0';
     if(secElem >= 10 && secElem <=26){
              // char secChar = 'a' + secElem - 1;
               secChar = 'a' + secElem - 1;
              print(input.substr(2),output+secChar);
        }
    }




    
   
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    print(input,output);
}
