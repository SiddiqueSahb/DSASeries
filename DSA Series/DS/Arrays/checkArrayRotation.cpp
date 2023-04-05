//check array rotation and return the index value from which the array has been rotated.

//first approach
int arrayRotateCheck(int *input, int size){
// Check is array is rotated
  if (input[0] > input[size - 1]) {

    // Traverse the array
    for (int i = 0; i < size; i++) {

      // Index where element is greater
      // than the next element
      if (input[i] > input[i + 1])
        return i + 1;
    }
  }

  // Array is not rotated
  return 0;
   }
    

//second approach
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    int count = 1;
    bool check = false;
    for (int i = 0; i < size - 1; i++) {
      if (input[i] <= input[i + 1]) {
        count++;
      } else {
        check = true;
        break;
      }
    }
    if (check == false) {
      return 0;
    } else {
      return count;
    }
   }