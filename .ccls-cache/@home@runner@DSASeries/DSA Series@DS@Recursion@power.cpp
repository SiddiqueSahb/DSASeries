// Online C++ compiler to run C++ program online
/*
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)

*/

#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

int power(int a , int n){
    //base case
    if(n == 0){
        return 1;
    }
    return  a * power(a,n-1);
   
}

int main() {
    // Write C++ code here
    int n ;
   cout<<"Enter no"<<endl;
   cin>>n;
   int p = power(2,n);
   cout<<"Ans of 2 power "<<n<<" is "<<p<<endl;
   
}