// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

//Staircase
int stairCase(int n){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    
    int ans = stairCase(n-1) + stairCase(n-2);
    return ans;
}


int main() {
    // Write C++ code here
    int n ;
   cout<<"Enter no"<<endl;
   cin>>n;
   int ans = stairCase(n);
   cout<<ans<<endl;
   
}