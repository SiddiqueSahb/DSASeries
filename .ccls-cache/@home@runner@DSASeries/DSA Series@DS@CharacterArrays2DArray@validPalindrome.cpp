// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstring>
using namespace std;

//checking valid char 
bool validChar(char ch){
    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
      return false;
}

//convert to lowercase
char toLowerCase(char ch){
     if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//After removing unwanted characters checking palindrome
bool checkPalindrome(string a){
    int start = 0;
    int len = a.length();
    int end = len - 1;
    while(start<=end){
        if( a[start] != a[end] ){
            return false;
    }
    else {
        start++;
        end--;
    }
    }
    return true;
}


//Here we are removing unwanted characters and convert to lower case if any uppercase
bool isPalindrome(string s){
   int i = 0;
   string temp = "";
   //removing unwanted characters like special cases @,$
   for(int j = 0;j<s.length();j++){
       if(validChar(s[j])){
           temp.push_back(s[j]);
       }
   }

   //converting to lowercase
   for(int j = 0;j<temp.length();j++){
       temp[j] = toLowerCase(temp[j]);
   }
   return checkPalindrome(temp);
}

int main() {
    // Write C++ code here
   char str[100]= "ab@@dba";
   bool val = isPalindrome(str);
    if(val){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not palindrome"<<endl;
    }
}
