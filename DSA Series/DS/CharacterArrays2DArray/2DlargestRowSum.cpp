// Online C++ compiler to run C++ program online


#include <iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;

void printRowSum(int arr[][3],int row,int col){
    cout<<"Printing sum row wise... "<<endl;
    for(int row = 0;row<3;row++){
        int sum = 0;
        for(int col = 0;col<3;col++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

//Col wise sum calculate
void printColSum(int arr[][3],int row,int col){
    cout<<"Printing sum col wise... "<<endl;
    for(int col = 0;col<3;col++){
        int sum = 0;
        for(int row = 0;row<3;row++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

//finding largest row sum in an array
int findLargestRowSum(int arr[][3],int row,int col){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int row = 0;row<3;row++){
        int sum = 0;
        for(int col = 0;col<3;col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }
    
    cout<<"Maximum sum is "<<maxi<<endl;
    return rowIndex;
}

int main() {
    // Write C++ code here
    
    int arr[3][3];
    
    cout<<"Enter elements "<<endl;
    //input row wise
    for(int row = 0;row<3;row++){
        for(int col = 0;col<3;col++){
            cin>>arr[row][col];
        }
    }
    
    //taking input col wise
    // for(int col = 0;col<3;col++){
    //     for(int row = 0;row<3;row++){
    //         cin>>arr[row][col];
    //     }
    // }
    
    //print row wise 2D array
    for(int row = 0;row<3;row++){
        for(int col = 0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    
    // printRowSum(arr,3,3);
    // printColSum(arr,3,3);
    int index = findLargestRowSum(arr,3,3);
    cout<<"Max sum is at index "<< index<<endl;
    
}

/*
Enter elements 
3 4 11 2 12 1 7 8 7
3 4 11 
2 12 1 
7 8 7 
Printing sum row wise... 
18 15 22 
Printing sum col wise... 
12 24 19 
*/

