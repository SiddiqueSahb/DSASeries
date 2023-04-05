// Online C++ compiler to run C++ program online

//WAVE PRINT

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

void wavePrint(int arr[][3],int nrow,int mcol){
    for(int col = 0;col<mcol;col++){
        
        //checking odd
        if(col&1){
            //if col no is odd then printing bottom to top
            cout<<"bottom to top"<<endl;
            for(int row = nrow-1;row>=0;row--){
                cout<<arr[row][col]<<endl;
            }
        }
        else {
             //even col and printing top to down
             cout<<"top to bottom"<<endl;
             for(int row = 0;row<nrow;row++){
                cout<<arr[row][col]<<endl;
            }
        }
    }
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
    cout<<endl;
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
    cout<<"PRINTING WAVE "<<endl;
    wavePrint(arr,3,3);
    
    // printRowSum(arr,3,3);
    // printColSum(arr,3,3);
   
    
}

/*
Enter elements 
/tmp/FJzLr6O1WM.o
Enter elements 
3 4 11 2 12 1 7 8 7
3 4 11 
2 12 1 
7 8 7 
PRINTING WAVE 
top to bottom
3
2
7
bottom to top
8
12
4
top to bottom
11
1
7

*/

