#include <iostream>
using namespace std;

int power(int number,int powerNo){
    int ans = 1;
    int i;
    for(i = 1;i<=powerNo;i++){
        ans = ans * number;
    }
    return ans;
}

int main() {
   int number,powerNo;
   cout<< "Enter the number and its power"<<endl;
   cin>> number>> powerNo;
   int answer = power(number,powerNo);
   cout<<"answer is "<<answer<<endl;
   
}

/*
Enter the number and its power
2
4
answer is 16
*/