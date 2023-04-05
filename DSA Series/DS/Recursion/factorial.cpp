// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}


int main(){
    int n;
  cout<<"Enter a no "<<endl;
  cin>>n;
  int fact = factorial(n);
  cout<<"Factorial of - "<<n<<" is "<<fact<<endl;
  
}