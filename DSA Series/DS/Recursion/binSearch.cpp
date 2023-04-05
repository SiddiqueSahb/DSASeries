// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

int linearSearch(int arr[],int size,int key){
    //base case
    if(size == 0){
        return 0;
    }
    
    if(arr[0] == key){
        return true;
    }
    else {
        bool remainPart = linearSearch(arr+1,size-1,key);
        return remainPart;
    }
}

bool binarySearch(int arr[],int s,int e,int key){
    //base case
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;
    
    //element found
    if(arr[mid] == key){
        return true;
    }
    
    //right part
    if(arr[mid] < key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}

int main() {
    // Write C++ code here
    int arr[5] = {2,4,6,8,9} ;
    int size = 5;
    int key = 9;
   bool ans = binarySearch(arr,0,size-1,key);
   if(ans){
       cout<<"key is found"<<endl;
   }else{
       cout<<"key is not found"<<endl;
   }
}

//output
/*

*/