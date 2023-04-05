// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no"<<endl;
    cin>>n;
    
    int ans = 0;
    while(n!=0){
        int digit = n % 10;
        // if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
        //     return 0;
        // }
        ans = (ans * 10) + digit;
        n = n / 10;
       
    }
    cout<<"answer is "<<ans<<endl;
}

/*
Enter the no in binary format
101
answer is 5
*/