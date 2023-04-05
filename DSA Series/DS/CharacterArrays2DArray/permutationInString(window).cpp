// Online C++ compiler to run C++ program online


#include <iostream>
#include<string>
using namespace std;

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

bool checkEqual(int a[26],int b[26]){
    for(int i = 0;i<26;i++){
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

bool permutationInString(string s1, string s2){
    
    //creating count of char of string 1
    //yaha pe s1 ke elements ka count increment karne ka
    int count1[26] = {0};
    for(int i = 0;i<s1.length();i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }
    
    //traverse s2 string by creating window of size s1 and compare both char count array
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    
    //ye s2 string ke elements jo window mein present hai unke count ko increase karna hai count2 array mein
    while(i<windowSize && i<s2.length()){
        int index = s2[i]-'a';
        count2[index]++;  //incrementing count of s2 array
        i++;
    }
    
    if (checkEqual(count1 , count2)){
        return 1;
    }
    
    //abhi aage ke window ko check karna toh uska age badho aur window mein ek new char add hoga aur 1st wala remove hoga.
    //jo char add hoga uska count increment karo aur jo remove hoga uska decrement karo
    
    while(i<s2.length()){
        
        //new char ko add karo
        char newChar = s2[i];
        int index = newChar -'a';
        count2[index]++;
        
        //old char ko remove karo uska count decrement karke
        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;
        
         i++;
        //newchar ko add and oldchar ko remove karke wapas compare karo
         if (checkEqual(count1 , count2)){
        return 1;
    }
    }
    return 0;
}

int main() {
    // Write C++ code here
    string s = "daabcbaabcbc";
    string part = "abc";
    bool per = permutationInString("ab", "eidbaooo");
    if(per){
        cout<<"permutation present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }
}
