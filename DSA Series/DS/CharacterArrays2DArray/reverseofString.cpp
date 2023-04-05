// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//length of string
int length(char input[]){
 int count = 0;
 for(int i = 0;input[i]!='\0';i++){
     count ++;
 }
 return count;
}

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
cout<<"Enter a string"<<endl;
cin.getline(input,100);
reverseString(input);
cout<<"String after reversal"<<endl;
cout<<input<<endl;
}

/*
Enter a string
hello world
String after reversal
dlrow olleh
*/