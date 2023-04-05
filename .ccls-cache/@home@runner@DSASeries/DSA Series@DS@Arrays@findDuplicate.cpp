int duplicateNumber(int *arr, int size)
{
    //Write your code here
    int ans = 0;
    for (int i = 0; i < size; i++) {
      ans = ans ^ arr[i];
    }

    for (int i = 0; i < size - 1; i++) {
      ans = ans ^ i;
    }
   return ans;
}