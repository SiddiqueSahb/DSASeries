// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m , int arr3[]){
    int i = 0,j=0,k=0;
    while(i<n && j<m){
        arr3[k++]=arr1[i++];
    }
    //copying array one remaining element to third array
    while(i<n){
        arr3[k++]=arr1[i++];
    }
        //copying array two remaining element to third array
    while(j<m){
        arr3[k++]=arr2[j++];
    }
}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
int arr1[5] = {1,3,5,7,9};
int arr2[3] = {2,4,6};

int arr3[8] = {0};
merge(arr1,5,arr2,5,arr3);
cout<<"PRINTING MERGED ARRAY"<<endl;
printArray(arr3,8);

}

/*
PRINTING MERGED ARRAY
1 3 5 7 9 2 4 6 
*/