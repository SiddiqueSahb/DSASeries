// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;

//find largest no in array
int largest(int arr[],int n){
    int max = INT_MIN;
    for(int i = 0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

//linear search
bool linearSearch(int arr[],int n,int x){
    for(int i = 0;i<n;i++){
        if(arr[i] == x){
              return 1;
        }
      return 0;
    }
    
}

//print array
void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//arrangement of no
void arrangeNo(int arr[],int n){
    int val = 1;
    int s = 0;
    int e = n-1;
    while(s<e){
        arr[s] = val;
        val++;
        arr[e] = val;
        val++;
        s++;
        e--;
    }
    if(s == e){
        arr[s]=val;
    }
    printArray(arr,5);
}

//swap alternate in array
void swapAlternate(int arr[],int n){
    for(int i = 0;i<n;i+=2){
        int j = i+1;
        if(j<n){
            swap(arr[i],arr[j]);
        }
    }
    printArray(arr,5);
}

int main() {
    // Write C++ code here
   int arr[5] = {1,2,12,4,5};
   int max = largest(arr,6);
   cout<<"Largest element "<<max<<endl; 
   cout<<endl;
   cout<<"Linear search starting.... "<<endl;
   bool ls = linearSearch(arr,6,3);
   if(ls){
       cout<<"Element is found"<<endl;
   }else{
       cout<<"Element not found"<<endl;
   }
   
   cout<<endl;
   cout<<"Arrange no starting.... "<<endl;
   arrangeNo(arr,5);
   
    cout<<endl;
   cout<<"swap alternate starting.... "<<endl;
   swapAlternate(arr,5);
   
}