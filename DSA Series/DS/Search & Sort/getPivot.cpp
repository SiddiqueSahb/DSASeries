#include <iostream>
#include<math.h>
#include <vector>
using namespace std;


int getPivot(int arr[],int n){
  int s = 0;
  int e = n-1;

  int mid = (s + e)/2;

  while(s<e){
    if(arr[mid]>=arr[0]){
      s = mid+1;
    }
    else{
      e = mid;
    }
    mid = (s + e)/2;
  }
  return s;
}

int main() {
 int oddarr[5] = {2,4,6,13,15};
 int index = getPivot(oddarr,5);
cout<<"Pivot elemt index in array is "<<index<<endl;
}

/*
Pivot elemt index in array is 4
*/