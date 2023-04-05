// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

int Fib(int n){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }
    int op1 = Fib(n-1);
    int op2 = Fib(n-2);
    return op1 + op2;
    
}


int main(){
    int n;
  cout<<"Enter a no "<<endl;
  cin>>n;
  int fib = Fib(n);
  cout<<"Fibonacci of - "<<n<<" is "<<fib<<endl;
  
}

/*
output
Enter a no 
3
Fibonacci of - 3 is 2
  */