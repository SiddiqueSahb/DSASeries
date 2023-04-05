/*
  Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
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
    char arr[100];
    cout<<"Enter a string"<<endl;
    cin.getline(arr,100);
     reverseWordwise(arr);
    cout<<arr<<endl;

}