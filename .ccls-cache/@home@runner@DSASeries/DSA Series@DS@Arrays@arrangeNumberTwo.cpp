// Online C++ compiler to run C++ program online
/*
  You have been given an empty array(ARR) and its size N. The only input taken from the user will be N and you need not worry about the array.
Your task is to populate the array using the integer values in the range 1 to N(both inclusive) in the order - 1,3,5,.......,6,4,2.
  */


#include <iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

int main() {
    // Write C++ code here
int n;
int arr[1000];
cout<<"Enter no of elements"<<endl;
cin>>n;
int val = 1;
int start = 0,end = n-1;
while(start<end){
    arr[start] = val;
    val++;
    arr[end] = val;
    val++;
    start++;
    end--;
}
if(start == end){
 arr[start] = val;
}

printArray(arr,n);

}