/*
For a given a string(str) and a character X, write a function to remove all the occurrences of X from the given string.
The input string will remain unchanged if the given character(X) doesn't exist in the input string.
Input Format:
The first line of input contains a string without any leading and trailing spaces.

The second line of input contains a character(X) without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string. 
  */

/*

yaha pe 2 pointer rakhna padega 

  */




void removeAllOccurrencesOfChar(char input[], char c) {
    // Write your code here
    int j = 0;
    for(int i =0;input[i] != '\0';i++){
        if(input[i] != c){
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
}
