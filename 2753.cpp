#include <iostream>

int main()
{
	auto a = 0;
	int leapyear = 1;
	int not_leap_year = 0;

	cin >> a;
	if (a >= 1 && a <= 4000 && a % 4 == 0 && a % 100 != 0)
		std::cout << leapyear;
	else if (a >= 1 && a <= 4000 && a % 4 == 0 && a % 400 == 0)
		std::cout << leapyear;
	else if (a < 1 && a > 4000)
		return 0;
	else if (a>=1 && a<=4000)
		std::cout << not_leap_year;

	return 0;
}
