#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int m = n;
    int mask = 0;
  
   //edge case 
    if (n == 0) {
        return 1;
    }
  
    while(m!=0){
    // mask - with each left shift we are making space and by doing OR we replace 0 with 1;    
       mask = (mask << 1) | 1;
       
       //doing right shift by 1 until we reach zero.
       //we are doing right shift to get the position of last 1 (last 1 from right to left)
       m = m >> 1;
    }
    ans = (~n) & mask;
    cout<<"answer is "<<ans<<endl;
}

/*
5
answer is 2
*/