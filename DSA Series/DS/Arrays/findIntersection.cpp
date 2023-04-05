// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// void printArray(int arr[],int n){
//     for(int i= 0 ; i<n;i++){
//         cout<<arr[i]<<"";
//     }
//     cout<<endl;
// }

int main() {
    // Write C++ code here
 int arr1[3] = {6,2,3};
 int arr2[5] = {2,6,2,3,4};
 int arr3[1000] = {0};
 int size1 = sizeof(arr1)/sizeof(arr1[0]);
 int size2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        if (arr1[i] == arr2[j]) {
          arr3[i] = arr1[i];
          cout << arr2[j]<<" ";
          arr2[j] = -2;
          break;
        }
      }
    }
//printArray(arr3,size3);
}