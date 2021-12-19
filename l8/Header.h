#include "math.h"
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex();
	Complex(double);
	Complex(double, double);
	double Phi() const;
	double R() const;
	double Re() const;
	double Im() const;
	Complex& operator+=(const Complex& right);
	Complex& operator-=(const Complex& right);
	Complex& operator*=(const Complex& right);
	Complex& operator/=(const Complex& right);
	Complex operator+ ( const Complex& right);
	Complex operator- ( const Complex& right);
	Complex operator* ( const Complex& right);
	Complex operator/ ( const Complex& right);
	Complex operator- ();
	explicit operator double()
	{
		return m_re;
	}
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& c);
private:
	double m_re = 0;      
	double m_im = 0;	

};

Complex cosh(const Complex& c);
