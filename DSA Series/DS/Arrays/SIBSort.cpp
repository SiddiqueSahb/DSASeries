// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//selectionSort
void selectionSort(int arr[],int n){
    int min;
    for(int i = 0;i<n-1;i++){
        min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

//bubbleSort
void bubbleSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

//InsertionSort
void insertionSort(int arr[],int n){
    for(int i = 1;i<n;i++){
        int temp = arr[i];
        int j;
        for(j = i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}


void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
}


int main() {
    // Write C++ code here
    int arr[5] = {6,2,8,4,0};
    //selectionSort(arr,5);
   // bubbleSort(arr,5);
   insertionSort(arr,5);
    printArray(arr,5);
    
}