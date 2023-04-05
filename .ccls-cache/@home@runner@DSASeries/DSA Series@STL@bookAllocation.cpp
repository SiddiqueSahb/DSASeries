// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

bool isPossibleSol(int arr,int n,int m,int mid){
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0;i<n;i++){
        if(pageSum + arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBook(int arr,int n,int m){
    int s = 0;
    int sum = 0;
    //calculatin sum
    for(int i = 0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum;
    int mid = s+ (e-s)/2;
    int ans = -1;
    
    while(s<=e) {
          //checking posssible solution
    if(isPossibleSol(arr,n,m,mid)){
        ans = mid;
        e = mid - 1;
    }
    else {
        s = mid + 1;
    }
    mid = s + (e-s)/2;
   }
  return ans;
}