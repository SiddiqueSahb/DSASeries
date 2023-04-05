// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
int arr[4] = {1,2,3,4};
int size = sizeof(arr)/sizeof(arr[0]);
int temp[4] = {0};
int k =2;
for(int i = 0;i<4;i++){
    temp[(i+k)%size]=arr[i];
}
cout<<"Rotated array"<<endl;
printArray(temp,4);

}
/*
Rotated array
3 4 1 2 
*/


//other approach
/*
void leftRotate(int arr[],int n){
    int temp = arr[0];
    int i;
    for(i = 0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[i]=temp;
}

void rotate(int *input, int d, int n)
{
    //Write your code here
   for(int i = 0;i<d;i++){
       leftRotate(input,n);
   }
}
*/

//Other approach
/*
void rotate(int *input, int d, int n)
{
    //Write your code here
    int temp[d];
    for (int i = 0; i < d; i++) {
      temp[i] = input[i];
    }

    for (int i = 0; i < n; i++) {
      input[i] = input[i + d];
    }
    int j = d - 1;
    for (int i = n - 1; i >= n - d; i--) {
      input[i] = temp[j];
      j--;
    }
}
*/