/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/26/2014 10:28:06 AM
 *
 *    Description:  create a complex number 
 *
 * ===========================================================================
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

using namespace std;

class Complex {
  private:
    int real;
    int imag;
  public:
    Complex();
    Complex(int r, int i);
    friend Complex operator+(const Complex & c0, const Complex & c1);
    Complex operator-(const Complex & s);
    friend Complex operator*(const Complex & c0, const Complex & c1);
    Complex operator~();
    friend ostream & operator<<(ostream & os, const Complex & c);
    friend istream & operator>>(istream & is, Complex & c);
};

#endif

Complex::Complex() {
  real = imag = 0;
}

Complex::Complex(int r, int i) {
  real = r;
  imag = i;
}

Complex operator+(const Complex & c0, const Complex & c1) {
  Complex sum;

  sum.real = c0.real + c1.real;
  sum.imag = c0.imag + c1.imag;

  return sum;
}

Complex Complex::operator-(const Complex & s) {
  Complex difference;

  difference.real = real - s.real;
  difference.imag = imag - s.imag;

  return difference;
}

Complex operator*(const Complex & c0, const Complex & c1) {
  Complex product;

  product.real = c0.real * c1.real;
  product.imag = c0.imag * c1.imag;

  return product;
}

Complex Complex::operator~() {
  Complex c;

  c.imag = -imag;
  c.real = real;

  return c;
}

ostream & operator<<(ostream & os, const Complex & c) {
  os << c.real << " " << c.imag << "i ";

  return os;
}

istream & operator>>(istream & is , Complex & c) {
  cout << "Input real part. \n";
  is >> c.real;
  cout << "Input imaginary part.\n";
  is >> c.imag;

  return is;
}

int main () {
  Complex a(3, 4);
  cout << "a is " << a << endl;
  Complex c;
  cout << "Enter a complex number.\n";
  cin >> c;
  cout << "c is " << c << endl;
  cout << a+c << endl;
  cout << a-c << endl;
  cout << a*c << endl;
  cout << ~c << endl;

  return 0;
}
