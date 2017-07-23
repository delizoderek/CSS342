/*
	Created by Derek DeLizo 4/11/2017
*/
#pragma once
#ifndef COMPLEX_H
#include <iostream>
#define COMPLEX_H
using namespace std;

class complex
{

friend ostream& operator<<(ostream&, const complex&);

friend istream& operator>>(istream&,complex&);

public:complex(double = 0.0,double = 0.0);        //Default constructor real = 0.0 and imaginary = 0.0
	   complex operator+(const complex&)const;    //Adding 2 complex numbers
	   complex operator-(const complex&)const;    //Subtracting 2 complex numbers
	   complex operator*(const complex&)const;    //Multiplying complex numbers
	   complex operator/(const complex&)const;    //The quotient of 2 complex numbers

	   complex& operator+=(const complex&);		  //current complex += other complex
	   complex& operator-=(const complex&);		  //current complex -= other complex
	   complex& operator*=(const complex&);		  //current complex *= other complex
	   complex& operator/=(const complex&);		  //current complex /= other complex

	   bool operator==(const complex&)const;	  //current complex equals other complex
	   bool operator!=(const complex&)const;	  //current complex does not equal other complex

public:
	complex conjugate();                          //the conjugate of the current complex number
	double getReal();                             //gets value of real
	double getImaginary();                        //gets value of imaginary

private:
	double real;                                  //real part of complex number
	double imaginary;                             //imaginary part of complex number
};
#endif // !COMPLEX_H

