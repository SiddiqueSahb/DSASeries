// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
//static
 vector<int> v;
 v.push_back(10);
 v.push_back(20);
 v.push_back(30);
 v.push_back(40);
 
 v.pop_back();
 
 v[1] = 100;
 
 // using this [] for get and update not for insertion
 //vector capacity is increased by twice of previous size
 
 cout<<v[0]<<endl;
 cout<<v[1]<<endl;
 cout<<v[2]<<endl;
 
 cout<<"Size : "<<v.size()<<endl;
 cout<<v.at(2)<<endl;
 cout<<v.at(6)<<endl;
 
 
 //dynamic
 vector<int> *vp = new vector<int>();
 

    return 0;
}