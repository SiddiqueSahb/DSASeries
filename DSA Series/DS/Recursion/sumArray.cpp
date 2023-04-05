// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

int getSum(int arr[],int size){
    //base case
    if(size == 0){
        return 0;
    }
    
    if(size == 1){
        return arr[0];
    }
    
    int sum = arr[0] + getSum(arr+1,size-1);
    return sum;
}



int main() {
    // Write C++ code here
    int arr[5] = {1,2,3,4,5} ;
    int size = 5;
    int ans = getSum(arr,5);
    cout<<"Sum of an array is "<<ans<<endl;
}

//output
/*
Sum of an array is 15
*/