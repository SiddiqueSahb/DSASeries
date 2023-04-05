#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	int digit;
	int sumODD = 0;
	int sumEven = 0 ;
	cin>>n;

	while(n){
	    digit = n%10;
	    if(digit & 1){
	        //do sum for odd no
	        sumODD += digit;
	    }
	    else{
	        sumEven += digit;
	    }
	     n = n/10;
	}
	cout<<"sumODD "<<sumODD<<endl;
	cout<<"sumEven "<<sumEven<<endl;
	
}
/*
1234
sumODD 4
sumEven 6
*/