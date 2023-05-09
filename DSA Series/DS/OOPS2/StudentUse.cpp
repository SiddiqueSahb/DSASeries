#include<iostream>
#include "Student.cpp"
using namespace std;

int main() {
char name[] = "abcd";
Student s1(20,name);
s1.display();

name[3] = "3";
//creating object s2 and sending parameter 24 and address of name(starting index);
//starting index of array we are copying that means Shallow copying(in class we copying this address)
Student s2(24,name);
s2.display();

s1.display();  

  Student s2(s1);
  s2.name[0] = 'x';
  s1.display();
  s2.display();

  Student s4,s5,s6; //whenever constructor is called totalStudent value is incremented
  	cout << Student :: getTotalStudent() << endl; // accessing function
}


/*
1.
class Student {
    public :

    int rollNumber;
    static int totalStudents;
};

int Student::totalStudents = 20;

int main() {
    Student s;
    // Correct statement to access totalStudents
}

o/p - Student :: totalStudents()


2.
class Student {
    public :

    int rollNumber;
    static int totalStudents;

    Student() {
        totalStudents++;
    }
};

int Student::totalStudents = 20;

int main() {
    Student s1, s2, s3, s4;
    cout << Student :: totalStudents;
}

o/p - 24

*/