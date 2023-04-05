// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool checkRotatedSorted(int arr[],int n){
    int count = 0;
    for(int i = 1;i<n;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[n-1] > arr[0]){
        count++;
    }
    
    return count<=1;
    
}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
//int arr[5] = {1,2,3,4,5};
//int arr[5] = {3,5,7,1,6};
int arr[5] = {1,1,1,1,1};
int size = sizeof(arr)/sizeof(arr[0]);
bool check = checkRotatedSorted(arr,size);
if (check){
    cout<<"Array is rotated and sorted"<<endl;
}
else{
   cout<<"Array is not rotated and sorted"<<endl; 
}
}

