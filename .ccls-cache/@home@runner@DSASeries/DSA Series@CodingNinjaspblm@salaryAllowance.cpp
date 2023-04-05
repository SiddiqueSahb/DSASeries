#include<iostream>
#include <cmath>
using namespace std;

int main() {
	// Write your code here
	long int basicSalary;
	int totalSalary;
	double hra,da,pf;
	char grade;
	cin>>basicSalary>>grade;

	hra = 0.2 * basicSalary;
	da = 0.5 * basicSalary;
	pf = 0.11 * basicSalary;
	if(grade =='A' ){
		totalSalary = round(basicSalary + hra + da + 1700 - pf);
		cout<<totalSalary<<endl;
	}
    else if (grade == 'B'){
      totalSalary = round(basicSalary + hra + da + 1500 - pf);
      cout <<totalSalary<< endl;
  }
  else {
    totalSalary = round(basicSalary + hra + da + 1300 - pf);
    cout <<totalSalary << endl;
  }
}

/*
4567 B
*/