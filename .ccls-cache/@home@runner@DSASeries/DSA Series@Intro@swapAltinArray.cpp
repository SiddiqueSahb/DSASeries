// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;


void swapAlternate(int arr[],int n){
for(int i = 0;i<n;i+=2){
    if(i+1<n){
        swap(arr[i],arr[i+1]);
    }
}
}


void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
 int evenArray[8] = {5,7,-10,4,6,8,3,2};
 int oddArray[5] = {5,7,-10,4,6};
 
 cout<< "Array before reverse"<<endl;
 printArray(evenArray,8);
 printArray(oddArray,5);
 
 
 swapAlternate(evenArray,8);
  swapAlternate(oddArray,5);
 
  cout<<"Array after swap"<<endl;
   printArray(evenArray,8);
   printArray(oddArray,5);
 
}

/*
Array before reverse
5 7 -10 4 6 8 3 2 
5 7 -10 4 6 
Array after swap
7 5 4 -10 8 6 2 3 
7 5 4 -10 6 

*/