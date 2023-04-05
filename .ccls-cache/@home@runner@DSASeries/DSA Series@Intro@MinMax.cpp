#include <iostream>
#include <climits>
using namespace std;

int getMax(int num[],int size){
    int max = INT_MIN;
    
    for(int i=0;i<size;i++){
        if(num[i]>max){
           max = num[i];
        }
    }
    return max;
}

int getMin(int num[],int size){
    int min = INT_MAX;
    
    for(int i=1;i<size;i++){
        if(num[i]<min){
           min = num[i];
        }
    }
    return min;
}



int main() {
   int num[100];
   int size;
   
   cout<<"Enter a size"<<endl;
   cin>>size;
   
   cout<<"enter a value"<<endl;
   for(int i = 1;i<size;i++){
       cin>>num[i];
   }
   int max = getMax(num,size);
   int min = getMin(num,size);
   
   cout<< "Max value" << max <<endl;
   cout<< "Min value" << min << endl;
   
}

/*
Enter a size
5
enter a value
-1 20 40 2 5
Max value 40
Min value -1
*/ 