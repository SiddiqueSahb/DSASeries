// Online C++ compiler to run C++ program online

//code not working
//WAVE PRINT 

#include <iostream>
#include<algorithm>
using namespace std;

void printRowSum(int **arr[][3],int row,int col){
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
  int row = sizeof(arr)/sizeof(arr[0]); 
    int col = sizeof(arr[0])/sizeof(arr[0][0]);
    
    int sRow = 0;
    int sCol = 0;
    int eRow = row -1;
    int eCol = col - 1;
    
    int count = 0;
    int total = nrow * mcol;
    
    while(count < total){
        
        //print starting row
        cout<<"Printing S ROW"<<endl;
        for(int i = sCol ; count < total && i<=eCol ; i++){
            cout<<arr[sRow][i]<<end;
            count ++;
        }
        sRow++;
        
         //print end col
        cout<<"Printing e col"<<endl;
        for(int i = sRow  ; count < total && i<=eRow ; i++){
            cout<<arr[i][eCol]<<end;
            count ++;
        }
        eCol--;
        
        
         //print end row
        cout<<"Printing e Row"<<endl;
        for(int i = eCol  ; count < total && i>=sCol ; i--){
            cout<<arr[eRow][i]<<end;
            count ++;
        }
        eRow--;
        
         //print s Col
        cout<<"Printing s Col"<<endl;
        for(int i = eRow  ; count < total && i>=sRow ; i--){
            cout<<arr[i][sCol]<<end;
            count ++;
        }
        sCol++;
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

