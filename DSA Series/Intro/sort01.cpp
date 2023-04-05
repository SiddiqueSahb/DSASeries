// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
#include <vector>
using namespace std;


void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

void sortOne(int arr[],int n){
    int left = 0;
    int right = n-1;
    
    while(left<right){
        //left side zero
        while(arr[left] == 0 && left<right){
            left++;
        }
        
        //right side one
        while(arr[right] == 1 && left<right){
            right--;
        }
        
        if(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        
        
    }
}
int main() {
 int arr[8] = {0,0,1,0,0,1,0,1};
 
 cout<<"Array before sorting"<<endl;
 printArray(arr,8);
 
 cout<<"Array after sorting"<<endl;
 sortOne(arr,8);
 printArray(arr,8);
}

/*
Array before sorting
00100101
Array after sorting
00000111

*/