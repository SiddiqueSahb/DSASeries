// Online C++ compiler to run C++ program online


#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int compressString(char s[]){
    int len = strlen(s);
    int i = 0;
    int ansIndex = 0;
    while(i<len){
        int j = i+1;
        while(j<len && s[i] == s[j]){
            j++;
        }
        
        s[ansIndex++] = s[i];
        
        int count = j-i;
        cout<<"Count of character "<<count<<endl;
        
        if(count>1){
            string cnt = to_string(count);
            for(char ch: cnt){
                s[ansIndex++]= ch;
            }
        }
        i=j;
    }
    
    for(int i=0;i<ansIndex;i++){
        cout<<s[i];
    }
    cout<<endl;
 return ansIndex;
}

int main() {
    char s[100] = "aabbbccc";
    int index = compressString(s);
    cout<<"Index"<<index<<endl;
}
