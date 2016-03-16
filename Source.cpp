#include <iostream>
#include <math.h>
using namespace std;


class Fraction{
private:
	int lower;
	int num;

	//finding hcf
	int HCF(int num1, int lower1){
		if (lower1 != 0){
			return HCF(lower1, num1%lower1);
		}
		else{
			return num1;
		}
	}

	Fraction operator+(Fraction num1, Fraction num2){
		return num1.add(num2);
	}
	Fraction operator-(Fraction num1, Fraction num2){
		return num1.sub(num2);
	}
	Fraction operator/(Fraction num1, Fraction num2){
		return num1.Divide(num2);
	}
	Fraction operator*(Fraction num1, Fraction num2){
		return num1.Multiply(num2);
	}



	void SF(int &rnum, int &rdenom, int &rWhole){   //getting into simplest form
		int hcf = HCF(rnum, rdenom);
		rnum = rnum / hcf;
		rdenom = rdenom / hcf;
		rWhole = rnum / rdenom;
		rnum = rnum - rdenom*rWhole;
	}


public:
	Fraction(int numerator = 1, int denominator = 1){
		lower = denominator;
		num = numerator;
	}


	void SetNumDenom(int numerator, int denominator){
		num = numerator;
		lower = denominator;
	}

	void GetNumDenom(int &rnum, int &rdenom){
		rnum = num;
		rdenom = lower;
	}



	Fraction add(Fraction num2){
		int lower2, Num2;
		num2.GetNumDenom(Num2, lower2);
		num = num * lower2;
		Num2 = Num2*lower;
		Fraction Result(num + Num2, lower * lower2);
		return Result;
	}



	Fraction sub(Fraction num2){
		int Denom2, Num2;
		num2.GetNumDenom(Num2, Denom2);
		num2.SetNumDenom(-Num2, Denom2);
		return add(num2);
	}



	Fraction Multiply(Fraction num2){
		int Num2, Denom2;
		num2.GetNumDenom(Num2, Denom2);
		Fraction Result(num * Num2, lower * Denom2);
		return Result;
	}

	Fraction Divide(Fraction num2){
		int Num2, Denom2;
		num2.GetNumDenom(Num2, Denom2);
		num2.SetNumDenom(Denom2, Num2);
		return Multiply(num2);
	}



	void Print(){
		int whole;
		int Num = num;
		int Denom = lower;
		SF(Num, Denom, whole);
		if (whole != 0 && Num != 0){
			cout << whole << " " << Num << "/" << abs(Denom) << endl;
		}
		else if (whole != 0){
			cout << whole << endl;
		}
		else if (Num != 0){
			cout << Num << "/" << abs(Denom) << endl;
		}
		else{
			cout << "0" << endl;
		}
	}


	~Fraction(){


	}
};

int main(){
	Fraction First(1, 3);
	Fraction Result(1, 2);
	First = First - Result;
	First.Print();
}
