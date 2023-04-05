// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//finding length of input
int length(char input[]){
 int count = 0;
 for(int i = 0;input[i]!='\0';i++){
     count ++;
 }
 return count;
}

//find all prefixes of input
void printPrefixes(char input[]){
    //i represents end of index
    for(int i =0;input[i]!='\0';i++){
        //j represents start of index
        for(int j = 0;j<=i;j++){
            cout<<input[j];
        }
        cout<<endl;
    }
}

//performing reverse of the string 
void reverseString(char input[]){
    int len = length(input);
    int i = 0;
    int j = len - 1;
    while(i<j){
       char temp = input[i];
       input[i] = input[j];
       input[j] = temp;
       i++;
       j--;
    }
}

int main() {
char input[100];
char input1[100] = "abcd";
cout<<"All prefix of input"<<endl;
printPrefixes(input1);
// cout<<"Enter a string"<<endl;
// cin.getline(input,100);
// reverseString(input);
// cout<<"String after reversal"<<endl;
// cout<<input<<endl;
}

/*
All prefix of input
a
ab
abc
abcd
*/