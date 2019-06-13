#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
	if(c1.get_imag() - c2.get_imag() < 0.0001) {
		if (c2.get_real() - c2.get_real() < 0.0001) {
			return false;
		}
	}
	return true;
}

ostream& operator<< (ostream& os, const Complex& c) {
    os << setprecision(3) << c.real << showpos << c.imag << "i" << noshowpos << endl;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	is >> c.real >> c.imag;
	return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::operator bool() const {
	return ((real != 0) || (imag != 0));
}

Complex& Complex::operator++() {
	++real;
	return (*this);
}

Complex Complex::operator++(int dummy) {
	Complex temp(*this);
	real++;
	return temp;
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex Complex::operator*(const int i) {
	return Complex(i * real, i * imag);
}