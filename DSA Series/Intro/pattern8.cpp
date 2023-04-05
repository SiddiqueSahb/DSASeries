#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
 // int count = 1; 1st method
  int value = row;
  
  while(row<=n){
      int col = 1;
      while(col<=row){
          // cout<<count<<" "; 1st method
        cout<<value<<" ";
       // count = count + 1; 1st method
        value = value + 1;
          col = col + 1;
      }
    cout<<endl;
     row = row + 1; 
  }
}

/*
1 
2 3 
4 5 6 

*/