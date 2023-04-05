#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
  int count =1 ;
  while(row<=n){
      int space = row - 1;
      while(space){
          cout<<" ";
          space = space - 1;
      }
    
    int col = 1;
    while(col<=n-row+1){
        cout<<count;
        col = col + 1;
    }
    cout<<endl;
    count = count + 1;
    row = row + 1;
  }
}

/*
1111
 222
  33
   4
*/