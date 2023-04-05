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



int main() {
    // Write C++ code here
    int arr[5] = {2,4,6,8,9} ;
    int size = 5;
    int key = 1;
   bool ans = linearSearch(arr,5,key);
   if(ans){
       cout<<"key is found"<<endl;
   }else{
       cout<<"key is not found"<<endl;
   }
}

//output
