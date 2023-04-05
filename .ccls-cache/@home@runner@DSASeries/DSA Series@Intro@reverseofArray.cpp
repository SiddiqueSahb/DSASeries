// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

void reverse(int arr[],int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
    
    int evenArr[8] = {5,7,-10,4,6,8,3,2};
    int oddArr[5] = {5,7,-10,4,6 };
    
    cout<< "Array before reverse"<< endl;
    printArray(evenArr,8);
    printArray(oddArr,5);
    
    reverse(evenArr,8);
    reverse(oddArr,5);
    
    cout<< "Array after reverse" << endl;
    printArray(evenArr,8);
    printArray(oddArr,5);
    
}

/*
Array before reverse
5 7 -10 4 6 8 3 2 
5 7 -10 4 6 
Array after reverse
2 3 8 6 4 -10 7 5 
6 4 -10 7 5 

*/