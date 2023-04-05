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
int arr[6] = {0,1,0,3,12,0};
int i = 0; 
for(int j = 0;j<6;j++){
    if(arr[j]!=0){
        swap(arr[j],arr[i]);
        i++;
    }
}
cout<<"Moved zeros to end of an ARRAY"<<endl;
printArray(arr,6);

}

/*
Moved zeros to end of an ARRAY
1 3 12 0 0 0 
*/