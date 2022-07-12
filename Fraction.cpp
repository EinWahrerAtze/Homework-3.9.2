#include "Fraction.h"

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
	Fraction result(1, 1);

	result.numenator_ = numenator_ * f.denominator_ + f.numenator_ * denominator_;
	result.denominator_ = denominator_ * f.denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator-()
{
	Fraction result(1, 1);

	result.numenator_ = -numenator_;
	result.denominator_ = denominator_;

	return  result;
}

Fraction Fraction::operator-(const Fraction & f)
{
	Fraction result(1, 1);
	
	result.numenator_ = numenator_ * f.denominator_ - f.numenator_ * denominator_;
	result.denominator_ = denominator_ * f.denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator*(const Fraction & f)
{
	Fraction result(1, 1);

	result.numenator_ = numenator_ * f.numenator_;
	result.denominator_ = denominator_ * f.denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator/(const Fraction & f)
{
	Fraction result(1, 1);

	result.numenator_ = numenator_ * f.denominator_;
	result.denominator_ = denominator_ * f.numenator_;

	int n = gcd(result.numenator_, result.denominator_);

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
	Fraction result(1, 1);

	result.numenator_ = numenator_ + denominator_;
	result.denominator_ = denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator++(int)
{
	Fraction result(1, 1);

	result.numenator_ = numenator_ + denominator_;
	result.denominator_ = denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator--()
{
	Fraction result(1, 1);

	result.numenator_ = numenator_ - denominator_;
	result.denominator_ = denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

Fraction Fraction::operator--(int)
{
	Fraction result(1, 1); 
	result.numenator_ = numenator_ - denominator_;
	result.denominator_ = denominator_;

	int n = gcd(result.numenator_, result.denominator_);

	return result / n;
}

int Fraction::gcd(int x, int y)
{
	if (y == 0)
	{
		return (x < 0 ? -x : x);
	}
	else
	{
		gcd(y, x % y);
	}
}