#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
  int count = row;
  while(row<=n){
      int space = row - 1;
      while(space){
          cout<<"_";
          space = space - 1;
      }
    
    int col = 1;
    count = row;
    while(col<=n-row+1){
        cout<<count;
        count = count + 1;
        col = col + 1;
    }
    cout<<endl;
    row = row + 1;
  }
}

/*
1234
_234
__34
___4

*/