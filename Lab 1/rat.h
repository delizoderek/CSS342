// a Rational object holds one Rational number, one fraction
/*
Project: Lab 1
Author: Derek DeLizo
*/
#include <iostream>
#ifndef RAT_H
#define RAT_H
using namespace std;

class Rational {	// not fully commented

friend istream& operator>>(istream&,Rational&);
friend ostream& operator<<(ostream&,const Rational&);

public:
   Rational(int = 0, int = 1);             // default constructor
   Rational add(const Rational &);
   Rational subtract(const Rational &);
   Rational multiply(const Rational &);
   Rational divide(const Rational &);
   Rational operator+(const Rational &);
   Rational operator-(const Rational &);
   Rational operator*(const Rational &);
   Rational operator/(const Rational &);
   Rational& operator+=(const Rational &);
   
   bool operator==(const Rational &);
   bool operator!=(const Rational &);
   bool operator>(const Rational &);
   bool operator>=(const Rational &);
   bool operator<(const Rational &);
   bool operator<=(const Rational &);
   
   void printRational();
   void printRationalAsFloat();

   int getNumerator();
   int getDenominator();

private:
   int numerator;
   int denominator;

   void reduce();                 // utility function, reduce to lowest terms
};

#endif

