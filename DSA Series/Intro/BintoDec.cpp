// Online C++ compiler to run C++ program online
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the no in binary format"<<endl;
    cin>>n;
    
    int ans = 0;
    int i = 0;
    while(n!=0){
        int digit = n % 10;
        
        if (digit==1){
            ans = ans + pow(2,i);
        }
        n = n / 10;
        i++;
    }
    cout<<"answer is "<<ans<<endl;
}

/*
Enter the no in binary format
101
answer is 5
*/