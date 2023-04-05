// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isEven(int no){
    if(no&1){
         //odd
        return 0;
    }
    //even
    return 1;
}

int main() {
   int number;
   cout<< "Enter the number to check even or odd"<<endl;
   cin>> number;
   int answer = isEven(number);
   if (answer){
       cout << "Number is even"<< endl;
   }
   else {
       cout <<" Number is odd "<< endl;
   }
   
}

/*
Enter the number to check even or odd
5
Number is odd 
*/