/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/



#include <string>
using namespace std;
int keypad(int num,string output[],string options[])
{
     if(num==0){
        output[0]="";
        return 1;
     }
    int last=num%10;
    int small=num/10;
    string smalloutput[500];
    int smallcount=keypad(small,smalloutput,options);
    string op=options[last];
    int k=0;
    for(int i=0;i<op.length();i++)
    {
        for(int j=0;j<smallcount;j++)
        {
            output[k]=smalloutput[j]+op[i];
            k++;
        }
       
    }
        return k;
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   string options[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return keypad(num,output,options);
}


//codingNinjas approach 2

int keypad(int n,string output[],string mapping[]){
  if(n == 0){
    output[0] = " ";
    return 1;
  }

  int digit = n%10;
  int smallNo = n/10;
  int smallOutputsize = keypad(n,output,mapping);

  string options = mapping[digit];

  //making copy of output
  for(int i = 0;i<options.length()-1;i++){
    for(int j = 0;j<smallOutputsize;i++){
      output[j+(i+1)*smallOutputsize] = output[j];
    }
  }

  //adding element for each output
  int k = 0;
  for(int i = 0;i<options.length()-1;i++){
    for(int j = 0;j<smallOutputsize;i++){
      output[k] = output[k] + options[i];
      k++;
    }

    return smallOutputsize * options.length();
  }
  
}