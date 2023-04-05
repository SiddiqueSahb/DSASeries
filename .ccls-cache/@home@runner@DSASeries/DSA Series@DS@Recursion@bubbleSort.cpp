// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;


void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortArray(int *arr,int n){
    //base case
    if(n == 0 || n == 1){
        return ;
    }
    
    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    sortArray(arr,n-1);
}


int main() {
    // Write C++ code here
   int arr[5] = {2,5,1,6,9};
   sortArray(arr,5);
   cout<<"Sorted array.."<<endl;
   printArray(arr,5);
}

//output
/*
Sorted array..
1 2 5 6 9 
*/