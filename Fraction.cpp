#include "Fraction.h"

std::wostream & operator<<(std::wostream & os, const Fraction & f)
{
	if (f.numenator_ == f.denominator_)
	{
		return os << 1;
	}
	else if (f.numenator_ == 0)
	{
		return os << L"0";
	}
	else if (f.denominator_ == 1)
	{
		return os << f.numenator_;
	}
	else if (f.denominator_ == 0)
	{
		return os << L"inf";
	}
	else
	{
		return os << f.numenator_ << L"/" << f.denominator_;
	}
}

Fraction::Fraction(int numenator, int demominator)
{
	int n = std::gcd(numenator, demominator);
	numenator_ = numenator / n;
	denominator_ = demominator / n;
}

Fraction Fraction::operator+(const Fraction & f)
{
	int numenator = numenator_ * f.denominator_ + f.numenator_ * denominator_;
	int denominator = denominator_ * f.denominator_;
	return Fraction (numenator, denominator);
}

Fraction Fraction::operator-(const Fraction & f)
{
	Fraction tmp = f;
	return *this + (-tmp);
}

Fraction Fraction::operator*(const Fraction & f)
{
	return Fraction(numenator_ * f.numenator_, denominator_ * f.denominator_);
}

Fraction Fraction::operator/(const Fraction & f)
{
	return *this * Fraction (f.denominator_, f.numenator_);
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
	return *this * Fraction(-1, 1);
}