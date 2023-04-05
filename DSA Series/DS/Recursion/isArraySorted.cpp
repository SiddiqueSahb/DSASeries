// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

bool isSorted(int arr[],int size){
    //base case
    if(size == 0 || size == 1){
        return 1;
    }
    
    if(arr[0]>arr[1]){
        return false;
    }
    else {
        bool remainPart = isSorted(arr+1,size-1);
        return remainPart;
    }
}



int main() {
    // Write C++ code here
    int arr[5] = {5,4,6,8,9} ;
    int size = 5;
   bool ans = isSorted(arr,5);
   if(ans){
       cout<<"Array is sorted"<<endl;
   }else{
       cout<<"Array is not sorted"<<endl;
   }
   
   
}

//output
/*
Enter no
5
5 4 3 2 1 
1 2 3 4 5 
*/