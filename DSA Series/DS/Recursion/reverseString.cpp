// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

void reverseString(string& str,int i ,int j){
  //base case
  if(i>j){
      return ;
  }
  swap(str[i],str[j]);
  i++;
  j--;
  reverseString(str,i,j);
}



int main() {
    // Write C++ code here
   string s = "mohammad";
   reverseString(s,0,s.length()-1);
   cout<<"After reversing string"<<endl;
   cout<<s<<endl;
}

//output
/*
After reversing string
dammahom
*/