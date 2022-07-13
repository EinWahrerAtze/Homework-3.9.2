#pragma once
#include <iostream>

class Fraction
{
public:
	friend std::wostream & operator<<(std::wostream & os, const Fraction & f);
	Fraction(int numenator, int denominator);
	Fraction operator+(const Fraction & f);
	Fraction operator-();
	Fraction operator-(const Fraction & f);
	Fraction operator*(const Fraction & f);
	Fraction operator/(const int n);
	Fraction operator/(const Fraction & f);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
private:
	int gcd(int x, int y);			// Наибольший общий делитель
	int numenator_;					// Числитель
	int denominator_;				// Знаменатель
};