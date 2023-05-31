#include <algorithm>
void sort012(int *arr, int n)
{
    //Write your code here
     int i = 0,nextZero = 0,nextTwo = n-1;
    
    while(i<=nextTwo){
        if(arr[i]==1){
            i++;
        }
        else if(arr[i]==0){
            swap(arr[i],arr[nextZero]);
            i++;
            nextZero++;
        }
        else if(arr[i]==2){
            swap(arr[i],arr[nextTwo]);
            nextTwo--;
        }
       
    }
}