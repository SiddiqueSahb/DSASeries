// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

//decreasing order
void printD(int n){
    //base case
    if(n == 0){
        return ;
    }
    cout<<n<<" ";
    printD(n-1);
}

//increasing order
void printI(int n){
    //base case
    if(n == 0){
        return ;
    }
    printI(n-1);
    cout<<n<<" ";
}


int main() {
    // Write C++ code here
    int n ;
   cout<<"Enter no"<<endl;
   cin>>n;
   printD(n);
   cout<<endl;
   printI(n);
   
}

//output
/*
Enter no
5
5 4 3 2 1 
1 2 3 4 5 
*/