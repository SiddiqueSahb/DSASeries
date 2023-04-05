
#include <iostream>
#include<string>
using namespace std;

//eliminate all substring from string
string removeAllSubtrings(string s,string part){
    while(s.length()!=0 && s.find(part) < s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main() {
    // Write C++ code here
    string s = "daabcbaabcbc";
    string part = "abc";
    cout<<"String before removing all substrings from string "     <<s<<endl;
    cout<<"String after removal of all substrings - "<<part<<endl;
    cout<<"Output "<<removeAllSubtrings(s,part);
}

/*
String before removing all substrings from string daabcbaabcbc
String after removal of all substrings - abc
Output dab
*/