/*
Created by Derek DeLizo 4/11/2017
*/

#include "complex.h"
#include <iostream>
using namespace std;
/*
Pre-Condition: a and b must be doubles
Post Condition: A complex number with real = a and imaginary = to b
*/
complex::complex(double a, double b) {
	real = a;
	imaginary = b;
}

/*
Pre-Condition: s is a valid complex number
Post Condition: returns the sum of two complex numbers
*/
complex complex::operator+(const complex& s) const {
	complex sum;
	sum.real = s.real + real;
	sum.imaginary = s.imaginary + imaginary;
	return sum;
}

/*
Pre-Condition: s is a valid complex number
Post Condition: returns the difference of two complex numbers
*/
complex complex::operator-(const complex& s) const {
	complex difference;
	difference.real = real - s.real;
	difference.imaginary = imaginary - s.imaginary;
	return difference;
}

/*
Pre-Condition: s is of type complex
Post Condition: returns the prodcut of two complex numbers
*/
complex complex::operator*(const complex& s) const {
	complex product;
	product.real = (real * s.real) + (-1 * s.imaginary * imaginary);
	product.imaginary = (real * s.imaginary) + (s.real * imaginary);
	return product;
}

/*
Pre-Condition: s.real and s.imaginary do not equal zero; s is a complex number
Post Condition: returns the quotient of two complex numbers or a divide by 0 error
*/
complex complex::operator/(const complex& s) const {
	complex quotient;
	if (s.real != 0 || s.imaginary != 0) {
		double divisor = (s.real * s.real) + (s.imaginary * s.imaginary);
		quotient.real = ((real * s.real) + (imaginary * s.imaginary)) / divisor;
		quotient.imaginary = ((-1 * real * s.imaginary) + (s.real * imaginary)) / divisor;
	}
	else {
		cerr << "divide by 0 error";
		quotient.real = s.real;
		quotient.imaginary = s.imaginary;
	}

	return quotient;
}

/*
Pre-Condition: Current object exists and s is a complex
Post Condition: returns current object after adding s.real and s.imaginary
*/
complex& complex::operator+=(const complex& s) {
	real = real + s.real;
	imaginary = imaginary + s.imaginary;

	return *this;
}

/*
Pre-Condition: Current object exists and s is a complex
Post Condition: returns current object after subtracting s.real and s.imaginary
*/
complex& complex::operator-=(const complex& s) {
	real = real - s.real;
	imaginary = imaginary - s.imaginary;

	return *this;
}

/*
Pre-Condition: Current object exists and s is a complex
Post Condition: returns current object after multiplying s.real and s.imaginary
*/
complex& complex::operator*=(const complex& s) {
	real = (real * s.real) + (-1 * s.imaginary * imaginary);
	imaginary = (real * s.imaginary) + (s.real * imaginary);
	return *this;
}

/*
Pre-Condition: s.real and s.imaginary cannot = 0. S is a complex
Post Condition: returns current object after dividing s.real and s.imaginary
*/
complex& complex::operator/=(const complex& s) {
	if (s.real != 0 && s.imaginary != 0) {
		double divisor = (s.real * s.real) + (s.imaginary * s.imaginary);
		double tempReal = 0.0;
		tempReal = ((real * s.real) + (imaginary * s.imaginary)) / divisor;
		imaginary = ((-1 * real * s.imaginary) + (s.real * imaginary)) / divisor;
		real = tempReal;
	}
	else {
		cerr << "Divide by 0 ERROR!";
	}
	return *this;
}

/*
Pre-Condition: s is a complex number
Post Condition: returns true if s equals thee current complex number
*/
bool complex::operator==(const complex& s) const {
	bool retVal = false;
	if (real == s.real && imaginary == s.imaginary) {
		retVal = true;
	}
	return retVal;
}

/*
Pre-Condition: s is of type complex
Post Condition: returns true if s is not equalt to the current complex number
*/
bool complex::operator!=(const complex& s) const {
	bool retVal = false;
	if (real != s.real && imaginary != s.imaginary) {
		retVal = true;
	}
	return retVal;
}


/*
Pre-Condition: s does not equal null
Post Condition: prints out a complex in the format a+bi and a-bi if a and b are not 0,
				bi if a = 0, a if b = 0, and 0 if both a and b are 0
*/
ostream& operator<<(ostream& output, const complex &s) {
	if (s.real != 0 && s.imaginary != 0) {
		if (s.real != 0) {
			output << s.real;
		}
		if (s.imaginary != 0) {
			if (s.imaginary < 0) {
				output << "-";
				if (s.imaginary == 1) {
					output << "i";
				}
				else {
					output << (-1 * s.imaginary) << "i";
				}
			}
			else {
				if (s.imaginary == 1) {
					output << "+i";
				}
				else {
					output << "+" << s.imaginary << "i";
				}
			}
		}
	}
	else {
		output << 0;
	}

	return output;

}

/*
Pre-Condition: 1 - 2 doubles
Post Condition: creates a copmlex with a real part and imaginary part
*/
istream& operator>>(istream& input, complex& s)
{
	input >> s.real >> s.imaginary;
	return input;
}

/*
Pre-Condition: The complex number exists
Post Condition: returns a complex where the sign is flipped
*/
complex complex::conjugate() {
	complex conjugate;
	conjugate.real = real;
	conjugate.imaginary = -1 * imaginary;
	return conjugate;
}

/*
Pre-Condition: The complex number exists
Post Condition: returns real as a double
*/
double complex::getReal() {
	return real;
}

/*
Pre-Condition: The complex number exists
Post Condition: returns imaginary as a double
*/
double complex::getImaginary() {
	return imaginary;
}