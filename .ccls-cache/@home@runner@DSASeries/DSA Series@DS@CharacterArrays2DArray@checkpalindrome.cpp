// Online C++ compiler to run C++ program online
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters.
*/


#include <iostream>
#include<cstring>
using namespace std;

int main() {
    // Write C++ code here
   char str[100]= "abdba";
    int i = 0;
    int len = strlen(str);
    int j = len - 1;
    bool var = false;
    while(i<=j){
        if( str[i] != str[j] ){
         var = false;
         break;
    }
    else {
        i++;
        j--;
    }
    }
    var =true;
    if(var){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not palindrome"<<endl;
    }
}
