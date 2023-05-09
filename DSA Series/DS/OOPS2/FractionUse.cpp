#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction const f3; // we are making constant object and object is constant we cant make changes to any properties of this object
  //Calling default constructor and it will initialize value with garbage
  //for f3 object getter and setter is not allowed as it is constant.Only constant function can be called by f3 .
  //if getter becomes constant then we can call it.

  //constant function is which doesnt change any property of current object.

	cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

	f3.setNumerator(10);
}

