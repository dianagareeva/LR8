#include "Header.h"
#include "math.h"
#include<iostream>

Complex::Complex():
	m_re{ sqrt(0)}, m_im{ atan2(0, 0) }
{}
Complex::Complex(double re):
	m_re{ re }, m_im{ 0 }
{} 

Complex::Complex(double re, double im) :
	m_re{ re }, m_im{ im }
{}

double Complex::Re() const
{
	return m_re;
}
double Complex::Im() const
{
	return m_im;
}
double Complex::R() const
{
	return sqrt(pow(m_re, 2) * pow(m_im,2));
}
double Complex::Phi() const
{
	return atan2(m_im, m_re);
}

Complex Complex::operator- ()
{
	return Complex(-Re(), -Im());
}
Complex& Complex::operator+=(const Complex& right)
{
	*this = Complex(Re() + right.Re(), Im() + right.Im());
	return *this;
}
Complex& Complex::operator-=(const Complex& right)
{
	*this = Complex(Re() - right.Re(), Im() - right.Im());
	return *this;
}
Complex& Complex::operator*=(const Complex& right)
{
	*this = Complex(Re() * right.Re(), Im() * right.Im());
	return *this;
}
Complex& Complex::operator/=(const Complex& right)
{
	*this = Complex(Re() / right.Re(), Im() / right.Im());
	return *this;
}
Complex Complex::operator+ (const Complex& right)

{
	Complex res = *this;
	return res += right;
}
Complex Complex::operator- (const Complex& right)
{
	Complex res = *this;
	return res -= right;
}
Complex Complex::operator* (const Complex& right)
{
	Complex res = *this;
	return res *= right;
}
Complex Complex:: operator/ (const Complex& right)
{
	Complex res = *this;
	return res /= right;
}

ostream& operator<<(ostream& out, const Complex& c) 
{
	out << "(" << c.Re() << ", " << c.Im() << ")";
	return out;
}
istream& operator>>(istream& in, Complex& c)
{
	in >> c.m_re >> c.m_im;
	return in;
}

Complex cosh(const Complex& c)
{
	return Complex(cosh(c.Re()) * cos(c.Im()), sinh(c.Re()) * sin(c.Im()));
}

