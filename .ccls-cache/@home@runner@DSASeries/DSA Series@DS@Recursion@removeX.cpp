// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void removeX(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != 'x'){
        removeX(s+1);
    }else{
        int i = 1;
        for(;s[i]!='\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeX(s); //not s+1 bcz we reducing size of s by 1;
    }
}

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
  removeX(str);
  cout<<str<<endl;
}