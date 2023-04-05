#include <iostream>
#include <climits>
using namespace std;


bool search(int arr[],int size,int key){
    for(int i = 0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
        return 0;
    }
}


int main() {
    
    int arr[10] = {5,7,-10,4,6,8,3};
    int key;
    
    cout<<"Enter the element to search for"<<endl;
    cin>>key;
    
    bool found = search(arr,10,key);
    if(found){
        cout<<"Key is found"<<endl;
    }else {
        cout<<"Key is not found"<<endl;
    }
    
   
}

/*
Enter the element to search for
5
Key is found

Enter the element to search for
2
Key is not found
*/