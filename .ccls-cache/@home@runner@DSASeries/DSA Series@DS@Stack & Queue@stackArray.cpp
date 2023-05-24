// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
using namespace std;

class StackusingArray {
    int *data;
    int nextIndex; //top
    int capacity;

public :
    StackusingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }
    
    //return no size of stack
    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex == 0; // 0 == 0 - returns True or 4 == 0 - False
    }
    
    //insert element
    void push(int element){
        //before inserting checking whether stack is full or not
        if(nextIndex == capacity){
            cout<<"stack is full "<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    //delete element
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
        return data[nextIndex - 1];
    }
    
    
};

int main() {
    // Write C++ code here
    StackusingArray s(5);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    
    cout<< s.pop()<<endl;
    cout<< s.size() <<endl;
    cout<< s.isEmpty() <<endl;
    
    return 0;
}