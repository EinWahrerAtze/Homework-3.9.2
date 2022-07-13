#include "Fraction.h"
#define FIND_GCD (result.numenator_ > result.denominator_) ? gcd((result.numenator_), (result.denominator_)) : gcd((result.denominator_), (result.numenator_))
#ifndef FIND_GCD
#error FIND_GCD is not defined
#endif // !FIND_GCD

std::wostream & operator<<(std::wostream & os, const Fraction & f)
{
	return os << f.numenator_ << L"/" << f.denominator_;
}

Fraction::Fraction(int numenator, int denominator)
{
	numenator_ = numenator;
	denominator_ = denominator;
}

Fraction Fraction::operator+(const Fraction & f)
{
	Fraction result(numenator_ * f.denominator_ + f.numenator_ * denominator_,
					denominator_ * f.denominator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator-()
{
	Fraction result(numenator_ = -numenator_, denominator_);
	return  result;
}

Fraction Fraction::operator-(const Fraction & f)
{
	Fraction result(numenator_ * f.denominator_ - f.numenator_ * denominator_,
					denominator_ * f.denominator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator*(const Fraction & f)
{
	Fraction result(numenator_ * f.numenator_, denominator_ * f.denominator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator/(const Fraction & f)
{
	Fraction result(numenator_ * f.denominator_, denominator_ * f.numenator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator/(const int n)
{
	numenator_ = numenator_ / n;
	denominator_ = denominator_ / n;
	return *this;
}


Fraction Fraction::operator++()
{
	Fraction result(numenator_ + denominator_, denominator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator++(int)
{
	Fraction result = *this;
	operator++();
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator--()
{
	Fraction result(numenator_ - denominator_, denominator_);
	int n = FIND_GCD;
	return result / n;
}

Fraction Fraction::operator--(int)
{
	Fraction result = *this;
	operator--();
	int n = FIND_GCD;
	return result / n;
}

int Fraction::gcd(int a, int b)
{
	if (b == 0)
	{
		return (a < 0 ? -a : a);
	}
	else
	{
		gcd(b, a % b);
	}
}
