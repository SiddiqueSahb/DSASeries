#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r){
    
    int numerator = factorial(n);
    int denom = factorial(r) * factorial(n-r);
    return numerator/denom;
}


int main() {
   int n,r;
   cout<< "Enter the value of n and r in nCr"<<endl;
   cin>>n>>r ;
   int answer = nCr(n,r);
   cout<< "Answer of nCr is "<<answer<<endl;
   
}

/*
Enter the value of n and r in nCr
8
2
Answer of nCr is 28
*/