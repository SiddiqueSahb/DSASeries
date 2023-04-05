// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

int binarySearch(int arr[] , int size , int key){
    
    int start = 0;
    int end = size -1;
    int mid;
//    mid = (start + end)/2; // normal mid calculation
      mid = (start + (end - start)/2);  //  optimize mid calculation
      
      while(start<=end){
             if (key == mid) {
                 return mid;
      } 
      //go to right array
      if (key>arr[mid]){
          start = mid + 1;
      }
      else // left array
      {
          end = mid - 1;
      }
      
      mid = start + (end - start)/2;
      
      }
      return -1;
}

int main() {
 int evenarr[6] = {2,4,6,8,10,12};
 int oddarr[5] = {2,4,6,13,15};
 int key;
 cout<<"Enter key to search "<<endl;
 cin>>key;
 int index = binarySearch(evenarr,6,key);
 if(index==-1){
     cout<<"Key is not found"<<endl;
 }
 else {
     cout <<"key is found"<<endl;
 }
}
