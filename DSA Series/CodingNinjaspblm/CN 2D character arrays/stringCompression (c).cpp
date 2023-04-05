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

/*
#include <cstring>
string getCompressedString(string &input) {
    int n = 0;
    //while(input[n] != '\0'){ 
        //n++;
    //}
    string temp="";
	n=input.size();
    int i=0;//for traversing the entire vector
    int ansIndex = 0;
    int j;
    while(i < n)
    {
        j = i+1; //for comparing the next character we had taken j=i+1
		while(j<n && input[i] == input[j])
        {
            j++;
        }
        /* when you will come here ?
        either we had traversed the whole vector
        or we had encountered the new character */
        
        // store the old char
       //input[ansIndex++] = input[i];
   /*     temp+=input[i];
        int count  = j-i;
        if(count>1)
        {
            temp+= count+48;  
            //input[ansIndex++]=count+48;
        }
        //moving to the new different character
        i=j;
    }
   // input[ansIndex] = '\0';   
    return temp;
    
}

*/


