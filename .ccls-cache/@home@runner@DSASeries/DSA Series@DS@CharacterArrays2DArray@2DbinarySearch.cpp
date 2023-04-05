//Binary search in 2D array

void binarySearch(int arr[][3],int nrow,int mcol,int target){
  int row = sizeof(arr)/sizeof(arr[0]);  
  int col = sizeof(arr[0])/sizeof(arr[0][0]);

  int start = 0;
  int end = row * col - 1; //calculate karna hai last element ka index
  int mid = start + (end-start)/2;//mid calaculate kiye

  while(start<=end){

    int element = arr[mid/row][mid%row];
    //  mid/rowIndex = row no deta hai
    //  mid%rowIndex = col no deta hai

    if(element == target){
      return 1;
    }

    if(element < target){
      start = mid + 1;
    }
    else{
      end = mid - 1;
    }

    mid = start + (end-start)/2;
}
  }
