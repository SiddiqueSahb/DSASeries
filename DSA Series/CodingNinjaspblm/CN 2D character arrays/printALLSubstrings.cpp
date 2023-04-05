
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printSubstrings(char input[]) {
    // Write your code here
    for(int start = 0;input[start]!='\0';start++){
        for(int i = start;input[i]!='\0';i++){
             for(int j = start;j<=i;j++){
              cout<<input[j];
        }
        cout<<endl;
    }
      }
}

int main() {
char input[100];
char input1[100] = "abcd";
cout<<"All substings of input"<<endl;
printSubstrings(input1);
// cout<<"Enter a string"<<endl;
// cin.getline(input,100);
// reverseString(input);
// cout<<"String after reversal"<<endl;
// cout<<input<<endl;
}
