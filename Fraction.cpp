#include "Fraction.h"

std::wostream & operator<<(std::wostream & os, const Fraction & f)
{
	if (f.numenator_ == f.denominator_)
	{
		return os << 1;
	}
	else if (f.numenator_ == 0 || f.denominator_ == 0)
	{
		return os << 0;
	}
	else
	{
		return os << f.numenator_ << "/" << f.denominator_;
	}
}

Fraction::Fraction(int numenator, int demominator)
{
	numenator_ = numenator;
	denominator_ = demominator;
}

Fraction Fraction::operator+(const Fraction & f)
{
	Fraction result (numenator_ * f.denominator_ + f.numenator_ * denominator_, denominator_ * f.denominator_);
	int n = std::gcd(result.numenator_, result.denominator_);
	result.numenator_ = result.numenator_ / n;
	result.denominator_ = result.denominator_ / n;
	return result;
}

Fraction Fraction::operator-(const Fraction & f)
{
	Fraction result(-f.numenator_, f.denominator_);
	return result + (*this);
}

Fraction Fraction::operator*(const Fraction & f)
{
	Fraction result(numenator_ * f.numenator_, denominator_ * f.denominator_);
	int n = std::gcd(result.numenator_, result.denominator_);
	result.numenator_ = result.numenator_ / n;
	result.denominator_ = result.denominator_ / n;
	return result;
}

Fraction Fraction::operator/(const Fraction & f)
{
	Fraction result(f.denominator_, f.numenator_);
	return result * (*this);
}

Fraction Fraction::operator++()
{
	*this = *this + Fraction(1, 1);
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction result = *this;
	operator++();
	return result;
}

Fraction Fraction::operator--()
{
	*this = *this - Fraction(1, 1);
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction result = *this;
	operator--();
	return result;
}

Fraction Fraction::operator-()
{
	return (*this) * Fraction(-1, 1);
}