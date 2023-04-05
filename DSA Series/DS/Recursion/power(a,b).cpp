// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include<math.h>
using namespace std;


int power(int a,int b){
    //base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    int ans = power(a,b/2);
    
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a * ans * ans;
    }
}



int main() {
   int a,b;
   cout<<"Enter a value of a and b"<<endl;
   cin>>a>>b;
   int ans = power(a,b);
   cout<<"Answer "<<ans<<endl;
}

//output
/*
Enter a value of a and b
2 4
Answer 16

Enter a value of a and b
2 5
Answer 32
*/