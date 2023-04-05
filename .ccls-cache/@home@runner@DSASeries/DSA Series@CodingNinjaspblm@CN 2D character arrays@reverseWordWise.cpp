/*
 Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 


Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc
*/

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int length(char arr[]){
    int count = 0;
    for(int i = 0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

 void reverseCompleteString(char arr[]){
     int len = length(arr);
     int i = 0;
     int j = len - 1;
     
     while(i<j){
         char temp  = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         i++;
         j--;
     }
 }

 void reverse(char arr[],int start,int end){
     int len = length(arr);
     int i = start;
     int j = end;
     
     while(i<j){
         char temp  = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         i++;
         j--;
     }
 }
 
 void reverseWordwise(char arr[]){
     reverseCompleteString(arr);
     cout<<arr<<endl;
     reverseCompleteString(arr);
     cout<<"Starting reverse word wise"<<endl;
     int len = length(arr);
     int start = 0;
     int end = 0;
     int i;
     for(i = 0;arr[i] != '\0';i++) {
         if(arr[i] == ' '){
             end = i - 1;
             reverse(arr,start,end);
             start = i+1;
         }
     }
     end = i - 1;
     reverse(arr,start,end);
 }


int main() {
    // Write C++ code here
    char arr[100] = "Hello, I am Aadil!";
     reverseWordwise(arr);
    cout<<arr<<endl;
   
    /*
!lidaA ma I ,olleH
Starting reverse word wise
,olleH I ma !lidaA
*/

}