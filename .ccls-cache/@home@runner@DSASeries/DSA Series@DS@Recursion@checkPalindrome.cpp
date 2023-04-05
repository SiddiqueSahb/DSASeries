// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

bool checkPalindrome(string str,int i ,int j){
  //base case
  if(i>j){
      return true ;
  }
  if(str[i] != str[j]){
    return false;  
  }
  else{
     return checkPalindrome(str,i+1,j-1); 
  }
}



int main() {
    // Write C++ code here
   string s = "mohammad";
   bool ans = checkPalindrome(s,0,s.length()-1);
   if(ans){
      cout<<"it is a palindrome"<<endl; 
   }
   else{
     cout<<"Not a palindrome"<<endl;  
   }
}

//output
/*
After reversing string
dammahom
*/