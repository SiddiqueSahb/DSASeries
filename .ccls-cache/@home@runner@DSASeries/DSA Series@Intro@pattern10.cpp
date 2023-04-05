#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;
  int row = 1;
 
  while(row<=n){
      int col = 1;
      while(col<=n){
          char val = 'A' + row - 1;
          cout<<val;
          col = col + 1;
      }
    cout<<endl;
     row = row + 1; 
  }
}

/*
AAA
BBB
CCC

*/