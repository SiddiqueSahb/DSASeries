#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
  int count =1 ;
  while(row<=n){
      int space = n - row;
      while(space){
          cout<<"_";
          space = space - 1;
      }
    
    int col = 1;
    
    while(col<=row){
        cout<<count;
        col = col + 1;
    }
    cout<<endl;
    count = count + 1;
    row = row + 1;
  }
}

/*
___1
__22
_333
4444
*/