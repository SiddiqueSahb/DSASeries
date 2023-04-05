// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        // if i = 1 to < n then j = 0 to <n-i
        bool swapped = false;
        for(int j = 0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    
    for(int i = 0;i<n;i++){
       cout<<arr[i];
    }
}

int main() {
    // Write C++ code here
    int arr[5] = {7,1,4,3,9};
    bubbleSort(arr,5);
  
}