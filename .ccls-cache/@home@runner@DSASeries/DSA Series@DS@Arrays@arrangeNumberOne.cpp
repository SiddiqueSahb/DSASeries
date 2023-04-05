// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i= 0 ; i<n;i++){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

int main() {
    // Write C++ code here
int n;
int arr[1000];
cout<<"Enter no of elements"<<endl;
cin>>n;
int val;
if(n%2 == 0){
      val = 1;
     for(int i = 0;i<=(n-1)/2;i++){
        arr[i] = val;
        val = val + 2;
     }
     val = n;
   for(int i = ((n-1)/2 + 1);i<=(n-1);i++){
       arr[i] = val;
       val = val - 2;
    }
}
else {
     val = 1;
     for(int i = 0;i<=(n-1)/2;i++){
        arr[i] = val;
        val = val + 2;
     }
     val = n-1;
   for(int i = ((n-1)/2 + 1);i<=(n-1);i++){
       arr[i] = val;
       val = val - 2;
    }
}

printArray(arr,n);

}
