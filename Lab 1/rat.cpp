// a Rational object holds one Rational number, one fraction
/*
	Project: Lab 1
	Author: Derek DeLizo
*/
#include "rat.h"

//------------------------------ Rational ------------------------------------
// default constructor:  parameters are numerator and denominator respectively
// if the number is negative, the negative is always stored in the numerator
Rational::Rational(int n, int d) {
   numerator = d < 0 ? -n : n;
   denominator = d < 0 ? -d : d;
   reduce();
}


//--------------------------------- add --------------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::add(const Rational& a) {
   Rational t;

   t.numerator = (a.numerator * denominator) + (a.denominator * numerator);
   t.denominator = a.denominator * denominator;
   t.reduce();

   return t;
}

//------------------------------ subtract ------------------------------------
// subtraction of 2 Rationals, current object and parameter

Rational Rational::subtract(const Rational& s) {
   Rational t;

   t.numerator = (s.denominator * numerator) - (denominator * s.numerator);
   t.denominator = s.denominator * denominator;
   t.reduce();

   return t;
}

//------------------------------ multiply ------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::multiply(const Rational& m) {
   Rational t;

   t.numerator = m.numerator * numerator;
   t.denominator = m.denominator * denominator;
   t.reduce();

   return t;
}

//-------------------------------- divide ------------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero crashes
Rational Rational::divide(const Rational& v) {
   Rational t;
   if (v.denominator != 0) {
	   t.numerator = v.denominator * numerator;
	   t.denominator = denominator * v.numerator;
	   t.reduce();
   }
   else {
	   t.numerator = v.numerator;
	   t.denominator = v.denominator;
	   cerr << "Divide by 0!";
   }

   return t;
}

//--------------------------------- add --------------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::operator+(const Rational& a) {
   Rational t;

   t.numerator = (a.numerator * denominator) + (a.denominator * numerator);
   t.denominator = a.denominator * denominator;
   t.reduce();

   return t;
}

//------------------------------ subtract ------------------------------------
// subtraction of 2 Rationals, current object and parameter

Rational Rational::operator-(const Rational& s) {
   Rational t;

   t.numerator = (s.denominator * numerator) - (denominator * s.numerator);
   t.denominator = s.denominator * denominator;
   t.reduce();

   return t;
}

//------------------------------ multiply ------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::operator*(const Rational& m) {
   Rational t;

   t.numerator = m.numerator * numerator;
   t.denominator = m.denominator * denominator;
   t.reduce();

   return t;
}

//-------------------------------- divide ------------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero crashes
Rational Rational::operator/(const Rational& v) {
   Rational t;
   if (v.denominator != 0) {
	   t.numerator = v.denominator * numerator;
	   t.denominator = denominator * v.numerator;
	   t.reduce();
   }
   else {
	   t.numerator = v.numerator;
	   t.denominator = v.denominator;
	   cerr << "Divide by 0 ERROR!";
   }

   return t;
}

Rational& Rational::operator+=(const Rational& a)
{
	numerator = (numerator * a.denominator) + (a.numerator * denominator);
	denominator = denominator * a.denominator;
	reduce();

	return *this;
}

bool Rational::operator==(const Rational& a)
{
	bool retVal = false;
	if (numerator == a.numerator && denominator == a.denominator) {
		retVal == true;
	}
	return retVal;
}

bool Rational::operator!=(const Rational& a)
{
	bool retVal = true;
	if (numerator == a.numerator && denominator == a.denominator) {
		retVal == false;
	}
	return retVal;
}

bool Rational::operator>(const Rational& a)
{
	bool retVal = false;
	double t1 = double(numerator) / denominator;
	double t2 = double(a.numerator) / a.denominator;
	if (t1 > t2) {
		retVal = true;
	}
	return retVal;
}

bool Rational::operator>=(const Rational& a)
{
	bool retVal = false;
	double t1 = double(numerator) / denominator;
	double t2 = double(a.numerator) / a.denominator;
	if (t1 >= t2) {
		retVal = true;
	}
	return retVal;
}

bool Rational::operator<(const Rational& a)
{
	bool retVal = false;
	double t1 = double(numerator) / denominator;
	double t2 = double(a.numerator) / a.denominator;
	if (t1 < t2) {
		retVal = true;
	}
	return retVal;
}

bool Rational::operator<=(const Rational& a)
{
	bool retVal = false;
	double t1 = double(numerator) / denominator;
	double t2 = double(a.numerator) / a.denominator;
	if (t1 <= t2) {
		retVal = true;
	}
	return retVal;
}

istream& operator>>(istream& input,Rational& f){
	input >> f.numerator >> f.denominator;
	f.reduce();
	return input;
}

ostream& operator<<(ostream& output,const Rational& f){
	if(f.denominator == 0){
		output << "divide by 0 ERROR!!!";
	} else if(f.numerator == 0){
		output << 0;
	} else {
		output << f.numerator << " / " << f.denominator;
	}
	return output;
}

//---------------------------- printRational ---------------------------------
void Rational::printRational() {
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else if (numerator == 0)
      cout << 0;
   else
      cout << numerator << "/" << denominator;
}

//------------------------ printRationalAsFloat ------------------------------
void Rational::printRationalAsFloat() {  
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else
      cout << float(numerator) / float(denominator);
}

//-------------------------------- reduce ------------------------------------
// reduce fraction to lowest terms
void Rational::reduce() {
   int n = numerator < 0 ? -numerator : numerator;
   int d = denominator;
   int largest = n > d ? n : d;

   int gcd = 0;                                 // greatest common divisor

   for (int loop = largest; loop >= 2; loop--)
      if (numerator % loop == 0 && denominator % loop == 0) {
         gcd = loop;
         break;
      }

   if (gcd != 0) {
      numerator /= gcd;
      denominator /= gcd;
   }
}

int Rational::getNumerator(){
	return numerator;
}

int Rational::getDenominator(){
	return denominator;
}

