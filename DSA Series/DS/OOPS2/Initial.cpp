class Initial {
public :
int age;
const int rollNo; // we are not initializing here bcz for other objects we require different rollno.
int &x; // we want to initialize reference variable 

//Initialization is used for const data members and reference data members
//At a time of creation we must initialized  i.e the allocation is done, value of r is passed to rollNo (means - const int rollNo = r)
//We can also  initialized non constant value also
Initial(int r,int age) : rollNo(r) , age(age) , x(this->age) {
  //writing this.age bcz to differentiate between parameter age and class property age(this.age).
  
}

};

/*
1.
class Student {
    public :

    const int rollNumber;
    int age;

};


int main() {
    Student s1;
    s1.rollNumber = 101;
    s1.age = 20;

    cout << s1.rollNumber << " " << s1.age;

}

o/p - compilation error


2.class Student {
    public :

    const int rollNumber;
    int age;

    Student(int r, int a) : rollNumber(r), age(a) {
    }
};


int main() {
    Student s1(100, 23);
    cout << s1.rollNumber << " " << s1.age;
}

o/p - 100 23

3.
class Student {
    public :

    const int rollNumber;
    int age;

    int &x;

    Student(int r, int a) : rollNumber(r), age(a) {
    }
};


int main() {
    Student s1(100, 23);
    s1.x = age;
    cout << s1.rollNumber << " " << s1.age << " " << s1.x;
}

o/p - error as int &x need be initialized using initializing list
*/

