// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int i = 0;
    while(n!=0){
        int bit = n & 1;
        ans = (bit*pow(10,i)) + ans;
        n = n >> 1;
        i++;
    }
    cout<<"answer is "<<ans<<endl;
}

/*
5
answer is 101
*/