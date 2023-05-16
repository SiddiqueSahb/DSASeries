class Fraction {
private :
  int numerator;
  int denominator;

//parametrized constructor calling as there should'nt be garbage value
public :
  Fraction(int numerator,int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
  }

  void print(){
    cout<<this->numerator<<"/"<<this->denominator<<endl;
  }

  void simplify(){
    int gcd = 1;
    int j = min(this->numerator,this->denominator); //(4,20) gcd will always be not greater than min value
    for(int i = 1;i<=j;i++){
      if(this->numerator % i == 0 && this->denominator % i == 0){
        gcd = i; // whichever no divides both numerator and denominator that will be gcd;
      }
    }
    this->numerator = this->numerator / gcd;
    this->denominator = this->denominator / gcd;
  }

  void add(Fraction const &f2){
    int lcm = denominator /*of f1 */ * f2.denominator;
    int x = lcm/denominator;
    int y = lcm/f2.denominator;

    int num = x*numerator + (y*f2.numerator);
    numerator = num;
    denominator = lcm;

    simplify();
  }

void multiply(Fraction const &f2){
  numerator = numerator * f2.denominator;
  denominator = denominator * f2.denominator;

  simplify();
}
}