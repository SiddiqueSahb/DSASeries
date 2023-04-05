#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	int sqrt = 1;
	cin>>n;
	for(int i = 1;i<=n/2;i++){
	    cout<<i<<endl;
		if(i*i>n){
			sqrt = i-1;
			break;
		}
		else if(i*i==n){
			sqrt = i;
			break;
		}
	}
	cout<<"ans is "<<sqrt<<endl;
	
}