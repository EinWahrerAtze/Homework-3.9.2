#include "Fraction.h"

void cls()
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear")
#endif
}

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
	setlocale(LC_ALL, "ru_RU.UTF-8");

	int n = 0;
	int d = 0;
	wchar_t ans = L'0';
	const int SIZE = 2;
	Fraction * fractions[SIZE](nullptr);

	while (towupper(ans) != L'E')
	{
		for (int i = 0; i < SIZE; ++i)
		{
			std::wcout << L"Введите числитель дроби " << i + 1 << L": ";
			check_input(n);
			std::wcout << L"Введите знаменатель дроби " << i + 1 << L": ";
			check_input(d);

			if (d < 0)
			{
				n = -n;
				d = -d;
			}

			fractions[i] = new Fraction(n, d);
		}

		cls();

		std::wcout << *(fractions[0]) << L" + " << *(fractions[1]) << L" = " << *(fractions[0]) + *(fractions[1]) << L'\n';
		std::wcout << *(fractions[0]) << L" - " << *(fractions[1]) << L" = " << *(fractions[0]) - *(fractions[1]) << L'\n';
		std::wcout << *(fractions[0]) << L" * " << *(fractions[1]) << L" = " << *(fractions[0]) * *(fractions[1]) << L'\n';
		std::wcout << *(fractions[0]) << L" / " << *(fractions[1]) << L" = " << *(fractions[0]) / *(fractions[1]) << L'\n';

		std::wcout << L"++" << *(fractions[0]) << L" * " << *(fractions[1]) << L" = ";
		std::wcout << ++(*(fractions[0])) * *(fractions[1]) << L'\n';
		std::wcout << L"Значение дроби 1 = " << *(fractions[0]) << L'\n';

		std::wcout << *(fractions[0]) << L"-- * " << *(fractions[1]) << L" = ";
		std::wcout << (*(fractions[0]))-- * *(fractions[1]) << L'\n';
		std::wcout << L"Значение дроби 1 = " << *(fractions[0]) << L'\n';

		std::wcout << L"-(" << *(fractions[0]) << L") = " << -(*(fractions[0])) << L"\n\n";

		std::wcin.get();
		std::wcout << L"Чтобы перезапустить, нажмите 'R', 'E' чтобы выйти: ";
		std::wcin.get(ans);
		std::cin.ignore(32767, '\n');

		while (towupper(ans) != L'E' && towupper(ans) != L'R')
		{
			std::wcout << L"Введите 'R', 'E': ";
			std::wcin.get(ans);
			std::cin.ignore(32767, '\n');
		}

		cls();
	}

	for (int i = 0; i < SIZE; ++i)
	{
		delete fractions[i];
	}

	return 0;
}