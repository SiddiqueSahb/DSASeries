#include <iostream>
using namespace std;

int count(char str[]){
    if(str[0] == '\0'){
        return 0;
    }
    int len = count(str+1);
    return 1 + len;
}

int main() {
    // Write C++ code here
  char str[100];
  cin>>str;
  
  int l = count(str);
  cout<<"length of a string "<<endl;
  cout<<l<<endl;
}