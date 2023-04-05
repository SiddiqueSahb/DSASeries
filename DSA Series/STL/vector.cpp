#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    //vector capacity means - kitne value reh sakte hai (kitna memory assign hui hai) aur vector full hota hai uski capacity previous se double hoja ti hai.
    
    //vector size means - kitne values hai currently vector mein

//creating vector
  vector<int> v;
  cout<<"Vector capacity-> "<<v.capacity()<<endl;
  
 vector<int> a(5,1);
   cout<<"print vector a-> "<<endl;
for(int i:a){
    cout<<i<<"";
}cout<<endl;

//copying one vector to other
vector<int> last(a);//last(vector_name to be copied)
for(int i:last){
    cout<<i<<"";
}cout<<endl;
 
  
  //adding value in vector
  v.push_back(1);
  cout<<"Vector capacity-> "<<v.capacity()<<endl;
  
  //adding value in vector
  v.push_back(2);
  cout<<"Vector capacity-> "<<v.capacity()<<endl;
  cout<<"Vector size-> "<<v.size()<<endl;
  
   //adding value in vector
  v.push_back(3);
  cout<<"Vector capacity-> "<<v.capacity()<<endl;
  cout<<"Vector size-> "<<v.size()<<endl;
  
  //Element at repective index
  cout<<"Element at 2nd index-> "<<v.at(2)<<endl;
  
 //front and back
   cout<<"Front-> "<<v.front()<<endl;
   cout<<"Back-> "<<v.back()<<endl;

//before pop
cout<<"before pop-> "<<endl;
for(int i:v){
    cout<<i<<"";
}cout<<endl;

v.pop_back();

cout<<"after pop-> "<<endl;
for(int i:v){
    cout<<i<<"";
}cout<<endl;
  
  
}