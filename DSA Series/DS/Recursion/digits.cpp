int count(int n){
    //write your code here
    //base case
   static int c = 0;
    if(n == 0){
        return 0;
    }
    int digit = n%10;
    n = n/10;
    c++;
    count(n);
    return c;
}

//another approach
//noOfDigit
int noOfDigit(int n){
    if(n==0){
        return 0;
    }
    int d = n%10;
    return 1+ noOfDigit(n/10);
}