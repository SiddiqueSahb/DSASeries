#include <iostream>
using namespace std;


void selectionSort(int arr[],int n){
    for(int i=0 ; i<(n-1);i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
    swap(arr[min],arr[i]);
    }
    
    for(int i = 0;i<n;i++){
       cout<<arr[i];
    }
}

int main() {
    // Write C++ code here
    int arr[5] = {7,1,4,3,9};
    selectionSort(arr,5);
  
}