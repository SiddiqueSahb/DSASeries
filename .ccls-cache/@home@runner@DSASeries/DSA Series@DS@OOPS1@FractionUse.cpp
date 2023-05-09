#include<iostream>
#include "Fraction.cpp"
using namespace std;

int main() {
  Fraction f1(10,4);
  Fraction f2(15,4);

  f1.add(f2);
  
  f1.print();
  f2.print();

  f1.multiply(f2);
  f1.print();
  f1.print();
}