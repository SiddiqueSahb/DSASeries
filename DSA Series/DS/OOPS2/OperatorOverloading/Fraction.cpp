class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}

		void print() {
			cout << this -> numerator << " / " << denominator << endl;
		}

		void simplify() {
			int gcd = 1;
			int j = min(this -> numerator, this -> denominator);
			for(int i = 1; i <= j; i++) {
				if(this -> numerator % i == 0 && this -> denominator % i == 0) {
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}

		Fraction add(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}

//f2 is passed as an argument and operator+ is operator overloading acts as a + , object f1 is having this.
// Fraction f3 = f1.add(f2) or Fraction f3 = f1 + f2;
		Fraction operator+(Fraction const &f2) const {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}
//making function const bcz we are not doing changes in this.numerator or this.denominator
		Fraction operator*(Fraction const &f2) const {
			int n = numerator * f2.numerator;
			int d = denominator * f2.denominator;
			Fraction fNew(n, d);
			fNew.simplify();
			return fNew;
		}

        //if (f1 == f2)
		bool operator==(Fraction const &f2) const {
			return (numerator == f2.numerator && denominator == f2.denominator);
		}


		void multiply(Fraction const &f2) {
			numerator = numerator * f2.numerator;
			denominator = denominator * f2.denominator;
			
			simplify();
		}

// Pre-increment
		Fraction& operator++() {
			numerator = numerator + denominator;
			simplify();

      //Fraction f3 = ++f1;
      //return will send the content pointed by dereferencing pointer of f1(i.e this).
      //if calling fraction f3 = ++(++f1);
      //(++f1) is called, it will give answer which is store in temporary space and on that
      //++() - ++ is called which will increment the value but we want that value must not change on temporary space but on 
      // real space so it should return refernce(i.e (++f1) - ans of this will return reference and on that reference again ++ will work upon)
      //bcz of & , copy (i.e temporary space will not be created)
			return *this;
		}


	// Post-increment
		Fraction operator++(int) {
     // Fraction f3 = f1++; 
    // first copying the value of f1 to f3 then incrementing the value
			Fraction fNew(numerator, denominator);
			numerator = numerator + denominator;
			simplify();
			fNew.simplify();
			return fNew;
		}

Fraction& operator+=(Fraction const &f2) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
		  denominator = lcm;
			simplify();

			return *this;
		}


};
