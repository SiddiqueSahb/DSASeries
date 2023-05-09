#include<iostream>
#include "StudentClass.cpp"
using namespace std;



int main(){

  //create object statically
  StudentClass s1;
  s1.rollNo = 101;
  s1.setAge(28);
 // s1.age = 24;
  cout<<s1.getAge()<<endl;
  cout<<s1.display()<<endl;


  //create object Dynamically
  StudentClass *s2 = new StudentClass;
  (*s2).rollNo = 101; //or s2->rollNo = 101;
  s2 -> setAge(28);
// (*s2).age = 24; //or s2->age = 24;
    cout<< (*s2).getAge()<<endl; // or s2->getAge()
    cout<< (*s2).display()<<endl;


  //constructor calling
  //Constructor is called when an object is created, here when we create a s3 object, 
  //s3 object will be created , it will have template same as StudentClass.
  StudentClass s3(24,101);

  //copy Constructor - s4 object will be created same as s3.
  StudentClass s4(s3); // or StudentClass s4 = s3; - copy constructor not copy assignment

  StudentClass *s5 = new StudentClass(10,202);
  StudentClass s6(*s5);
  StudentClass *s7 = new StudentClass(*s5); //creating object 7 same as object s5


  //cpy assignment operator
  StudentClass s8(10,1001);
  StudentClass s9(20,2001);

  StudentClass *s10 = new StudentClass(30,3001);

  s8 = s9;  //copying all the object value of s9 to s8
  *s10 = s9; //copying all the object value of s9 to s10
  
  delete s10; //delete pointer before calling destructor

  //destructor ~StudentClass() will called before leaving main()
}




#include <iostream>
using namespace std;

class Student{
    public :
    char name;
    int rollNo;

    Student(int num){
        rollNo = num;
    }

    void print(){
        cout << name << " "  <<  rollNo;
    }
};

int main() {
    Student *s = new Student();
    s -> name = 'A';
    s -> rollNo = 15;
    s -> print();
}

/*
ANS- There is Compilation error - “constructor Student() is undefined” because the default constructor is available only till the point we don’t create our own constructor. So Student class has only one constructor which require roll number as argument, hence we should pass integer as argument while creating any Student object.
*/