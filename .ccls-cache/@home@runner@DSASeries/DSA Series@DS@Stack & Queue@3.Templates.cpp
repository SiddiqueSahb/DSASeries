// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


template <typename T,typename V>
class Pair{
    T x;  //T temporary datatype
    V y;
    public :
    
    void setX(T x){
        this->x = x;
    }
    
    T getX(){
        return x;
    }
    
   void setY(V y){
        this->y = y;
    }
    
    V getY(){
        return y;
    }
};

int main() {
    // Write C++ code here
    //when we are creating an object we are specifying the type
    // Pair<int> p1; // here x and y will of type int
    // Pair<double> p1; // here x and y will of type double
    
    // //creating an object having two property of different datatype
    // Pair<int,double> p3
    
    //Creating triplet with this same pair class
    Pair<Pair<int,int>,int> p4;  //pair T - Pair<int,int> V - int
    p4.setY(10);
    Pair<int,int> p5;
    p5.setX(5);
    p5.setY(16);
    p4.setX(p5);
    cout<<p4.getX().getX()<<endl;
    cout<<p4.getX().getY()<<endl;
    cout<<p4.getY()<<endl;
    
    return 0;
}