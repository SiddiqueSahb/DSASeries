class Student {
public :
int age;
int rollNumber;
char *name;  //for dynamically allocating space we are not deciding memory space here.
static int totalStudents;		// total number of students present , if we make this property private to access it we use  static int getTotalStudent(). 

public:
Student(int age,int name){
  this->age = age;
  //shallow copy means only copying starting address of array
  // this->name = name;

  //Deep Copy
  //Making copy of whole array
  this->name = new char[strlen(name) + 1]; //1 for null character "abcd\0" strlen gives len without null character.
  strcpy(this->name ,name);  //copy name value to this.name 
}

Student() {
		totalStudents++;
	}


	int getRollNumber() {
		return rollNumber;
	}

//as this function is working on static property funcn need to be static
//static func operates only on static properties
	static int getTotalStudent() {
		return totalStudents;
	}

//copy Constructor
Student(Student const &s){
  this->age = s.age;
 // this->name = s.name; //shallow copy in constructor

  //Deep Copy
  //Making copy of whole array
  this->name = new char[strlen(name) + 1]; //1 for null character "abcd\0" strlen gives len without null character.
  strcpy(this->name ,name); 

  
}

void display(){
  cout<< name <<" "<<age<<endl;
}

};

//static members initialization is done outside the class
//: : - scope resolution operator
int Student :: totalStudents = 0;	// initialze static data members
