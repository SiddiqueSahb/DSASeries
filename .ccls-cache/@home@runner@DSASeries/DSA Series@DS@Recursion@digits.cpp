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

//lovebabbar sayDigit problem lec32 day2 recursion