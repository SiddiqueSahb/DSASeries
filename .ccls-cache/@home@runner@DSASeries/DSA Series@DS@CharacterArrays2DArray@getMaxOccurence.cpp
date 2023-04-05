// Online C++ compiler to run C++ program online
/*
Highest Occuring Character
Send Feedback
For a given a string(str), find and return the highest occurring character.
Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

*/



#include <iostream>
#include<string>
using namespace std;

char getMaxOccurence(string s){
    int arr[26] = {0};
    
    //creating an array of count of characters
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        int val = 0;
        //getting the index of an array of particular alphabet and incrementing its count
        if(ch>='a' && ch<='z'){
            val = ch - 'a';
            arr[val]++;
        }
        else {
            val = ch - 'A';
            arr[val]++;
        }
    }
    
    //finding maximum occurence from an array
    int maxi = -1;
    int ans = 0;
    for(int i = 0;i<26;i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    
    return 'a'+ ans;
}

int main() {
    // Write C++ code here
  string s;
  cout<<"Enter a string "<<endl;
  cin>>s;
  cout<<"MAXIMUM OCCURENCE OF CHARACTER IN STRING "<<s<<endl;
  cout<<getMaxOccurence(s);
}

/*
Enter a string 
test
MAXIMUM OCCURENCE OF CHARACTER IN STRING test
t
*/