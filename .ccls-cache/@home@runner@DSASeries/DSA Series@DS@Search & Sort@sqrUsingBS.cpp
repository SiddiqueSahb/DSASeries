#include <iostream>
#include<math.h>
#include <vector>
using namespace std;

//for Integer part of square root
int squareRoot(int n){
    int s = 0;
    int e = n;
    int mid = (s+e)/2;
    int ans = -1;
    while(s<=e){
        int square = mid * mid;
        if(square == n){
            return mid;
        }
        if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

//Fraction part ko add karne ke liye
double morePrecision(int n,int precision,int tempSoln){
    double factor = 1;
    double ans = tempSoln;
    for(int i = 0;i<precision;i++){
        factor = factor/10;
        for(double j = ans;j*j<n;j = j + factor){
            ans = j;
        }
    }
    return ans;
}

int main() {
 int n;
 cout<<"Enter no to get the square root"<<endl;
 cin>>n;
 int tempSoln = squareRoot(n);
 cout<<"Square root is "<<morePrecision(n,3,tempSoln)<<endl;
}

/*
Enter no to get the square root
37
Square root is 6.082
*/