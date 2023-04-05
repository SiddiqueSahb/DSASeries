// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void findArraySum(int arr1[],int n,int arr2[],int m,int ans[]){
   int i = n-1;
   int j = m-1;
   int carry = 0;
   
   while(i>=0 && j>=0){
       int val1 = arr1[i];
       int val2 = arr2[j];
       int sum = val1 + val2 + carry;
       carry = sum/10;
       sum = sum%10;
       ans[i]=sum;
       i--;
       j--;
   }
   
   while(i>=0){
       int sum = arr1[i] + carry;
       carry = sum/10;
       sum = sum%10;
       ans[i]=sum;
       i--;
   }
   
     while(j>=0){
       int sum = arr2[j] + carry;
       carry = sum/10;
       sum = sum%10;
       ans[j]=sum;
       j--;
   }
   
     while(carry!=0){
       int sum = carry;
       carry = sum/10;
       sum = sum%10;
       ans[j]=sum;
       j--;
   }
   
   for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
}
}

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
int arr1[4] = {1,2,3,4};
int arr2[1] = {6};
int ans[10] = {0};
// int arr[5] = {1,1,1,1,1};
//int size = sizeof(arr)/sizeof(arr[0]);
cout<<"ARRAY 1"<<endl;
printArray(arr1,4);
cout<<"ARRAY 2"<<endl;
printArray(arr2,1);
cout<<"ARRAY after adding"<<endl;
findArraySum(arr1,4,arr2,1,ans);

}

/*
ARRAY 1
1 2 3 4 
ARRAY 2
6 
ARRAY after adding
1 2 4 0 
*/


//Approach 2
/*
  int i = size1-1, j = size2-1;
    int carry=0;
    int k;
    if(size1 < size2){
      k = size2;
    }
    else{
       k = size1;
    }
    while(k >= 0){
        output[k] = (input1[i]+input2[j]+carry)%10;
          carry = (input1[i]+input2[j]+carry)/10;
        if(i>0)
            i--;
        else{
            i=-1;
            input1[i] = 0;
        }
        if(j>0)
            j--;
        else{
            j=-1;
            input2[j] = 0;
        }
        k--;
    }
*/

