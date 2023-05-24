// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class StackusingArray {
    int *data;
    int nextIndex; //top
    int capacity;

public :
    StackusingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            //if stack is full , creating an array of double size of previous
            int *newData = new int[2*capacity];
            //copy array elements to new array
            for(int i = 0 ;i<capacity;i++){
                newData[i] = data[i];
                }
                capacity *= 2;
                //deleting old data 
                delete [] data;
                //assigning data as newData
                data = newData;
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
    StackusingArray s;
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