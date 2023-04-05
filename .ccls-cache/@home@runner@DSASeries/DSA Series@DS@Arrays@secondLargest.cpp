// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

int main() {
   int arr[7] = {2,6,1,9,8,9,7};
 //   int arr[7] = {2,2,2,2,2,2,2};
    int max = INT_MIN;
    int secMax = INT_MIN;
    for(int i = 0;i<7;i++){
        if(arr[i]>max && arr[i]!=max){
            secMax = max;
            max = arr[i];
        }
        else if (arr[i]>secMax & arr[i]!=max){
            secMax = arr[i];
        }
    }
    cout<<"Max "<<max<<endl;
    cout<<"second Max "<<secMax<<endl;
}

/*
for int arr[7] = {2,6,1,9,8,9,7};
Max 9
second Max 8


for int arr[7] = {2,2,2,2,2,2,2};
Max 2
second Max -2147483648
*/