#include "Fraction.h"

void check_input(int & n)
{
	while (!(std::wcin >> n) || (n == 0))
	{
		std::wcin.clear();
		while (std::wcin.get() != L'\n')
			continue;
		std::wcout << L"Пожалуйста, введите число не равное \"0\": ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;
	int d = 0;
	const int SIZE = 2;
	Fraction * frac_arr[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		std::wcout << L"Введите числитель дроби " << i + 1 << L": ";
		check_input(n);
		std::wcout << L"Введите знаменатель дроби " << i + 1 << L": ";
		check_input(d);
		frac_arr[i] = new Fraction(n, d);
	}
//	frac_arr[0]->operator+(*(frac_arr[1]));
	std::wcout << *(frac_arr[0]) << L" + " << *(frac_arr[1]) << L" = " << *(frac_arr[0]) + *(frac_arr[1]) << L'\n';
	std::wcout << *(frac_arr[0]) << L" - " << *(frac_arr[1]) << L" = " << *(frac_arr[0]) - *(frac_arr[1]) << L'\n';
	std::wcout << *(frac_arr[0]) << L" * " << *(frac_arr[1]) << L" = " << *(frac_arr[0]) * *(frac_arr[1]) << L'\n';
	std::wcout << *(frac_arr[0]) << L" / " << *(frac_arr[1]) << L" = " << *(frac_arr[0]) / *(frac_arr[1]) << L'\n';
//	frac_arr[0]->operator++();
//	frac_arr[0]->operator*(*(frac_arr[1]));
	std::wcout << L"++" << *(frac_arr[0]) << L" * " << *(frac_arr[1]) << L" = " << ++(*(frac_arr[0])) * *(frac_arr[1]) << L'\n';
	std::wcout << L"Значение дроби 1 = " << ++(*(frac_arr[0])) << L'\n';
	std::wcout << ++(*(frac_arr[0])) << L"-- * " << *(frac_arr[1]) << L" = " << (++(*(frac_arr[0])))-- * *(frac_arr[1]) << L'\n';
	std::wcout << L"Значение дроби 1 = " << --(++(*(frac_arr[0]))) << L'\n';
	std::wcout << *(frac_arr[0]) << L" - -(" << *(frac_arr[1]) << L") = " << *(frac_arr[0]) - -(*(frac_arr[1])) << L'\n';

	for (int i = 0; i < SIZE; ++i)
	{
		delete frac_arr[i];
	}

	return 0;
}