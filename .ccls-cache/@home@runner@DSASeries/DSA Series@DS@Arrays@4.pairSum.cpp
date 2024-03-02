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
 int input[9] = {1, 3 ,6 ,2, 5 ,4, 3, 2, 4};
 int sum = 7;
 int size1 = sizeof(input)/sizeof(input[0]);
  int count = 0;
    for (int i = 0; i < size1; i++) {
      for (int j = i+1; j < size1; j++) {
        if ((input[i] + input[j]) == sum) {
        if(input[i] < input[j]){
                        cout << input[i]<<" "<< input[j] << endl;
                    }
                    else{
                        cout << input[j]<<" "<< input[i] << endl;
                    }
          break;
        }
      }
    }
//printArray(arr3,size3);
  		return count;
}