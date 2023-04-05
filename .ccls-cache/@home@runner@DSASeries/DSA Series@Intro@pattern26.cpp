#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
  while(row<=n){
      //print 1st space triangle
      int space = n - row ;
      while(space){
          cout<<"_";
          space = space - 1;
      }
    
    //print 2nd triangle
    int col = 1;
    while(col<=row){
        cout<<col;
        col = col + 1;
    }
    
    //print 3rd triangle
    int start = row - 1;
    while(start){
        cout<<start;
        start = start - 1;
    }
    
    
    cout<<endl;
    row = row + 1;
  }
}

/*
___1
__121
_12321
1234321
*/