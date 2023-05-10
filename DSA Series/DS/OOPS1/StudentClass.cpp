//by default propeties are private
class StudentClass {
  public :
  int rollNo;  //properties
  private :
  int age;
  public :
  void display(){
    cout << age<< " "<<rollNo<<endl;
    
  }

//getter
  int getAge(){
    return age;
  }

//Setter
  void setAge(int a){
    age = a;
  }

//parameterized constructor
StudentClass(int r){
  rollNo = r;
}

//when parameter is passes from main and here it get.
StudentClass(int age,int rollno){
  //here how constructor will differtiate of which age rollNo we are discussing about.Whether it is of parameter or class property?.
  //So to get rid of the issue we have this keyword.
  //this , is a ptr variable which is having ptr to objects who have called.Here s3 object is created and this have access 
  //to its properties.
  //writing this before variable , we will be able to differentiate b/w paramter and object property
  this.rollNo = rollNo; // or this -> rollNo = rollNo
  this.age = age;
}

//Destructor
public :
~StudentClass(){
  
}
};

