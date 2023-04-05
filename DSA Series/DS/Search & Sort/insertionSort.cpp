void insertionSort(int *input, int size)
{
    //Write your code here
    int i = 1;
    int current;
    for(int i = 1;i<size;i++){
        current = input[i];
        int j;
        for(j = i-1;j>=0;j--){
            if(current<input[j]){
                input[j+1] = input[j];
            }
            else {
                break;
            }
        }
        input[j+1] = current;
    }
}