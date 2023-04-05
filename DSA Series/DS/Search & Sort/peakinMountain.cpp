#include <iostream>
#include<math.h>
using namespace std;


int peakinMountain(vector<int>& arr,int n){
  int s = 0;
  int e = arr.size()-1;

  int mid = (s + e)/2;

  while(s<e){
    if(arr[mid]<arr[mid+1]){
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
 int evenarr[6] = {2,4,6,12,8,10,;
 int oddarr[5] = {2,4,6,13,15};
 int index = peakinMountain(evenarr,6);
cout<<"Peak elemt in array "<<index<<endl;
}