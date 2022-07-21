#pragma once
#include <iostream>
#include <numeric>

class Fraction
{
public:
	friend std::wostream & operator<<(std::wostream & os, const Fraction & f);
	Fraction(int numenator, int denominator);
	Fraction operator+(const Fraction & f);
	Fraction operator-(const Fraction & f);
	Fraction operator*(const Fraction & f);
	Fraction operator/(const Fraction & f);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
	Fraction operator-();
private:
	int numenator_;					// Числитель
	int denominator_;				// Знаменатель
};