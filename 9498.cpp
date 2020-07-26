#include <iostream>

int main()
{
	auto a = 0;
	std::cin >> a;
	if (a >= 90 && a <= 100)
		std::cout << 'A';
	else if (a >= 80 && a <= 89)
		std::cout << 'B';
	else if (a >= 70 && a <= 79)
		std::cout << 'C';
	else if (a >= 60 && a <= 69)
		std::cout << 'D';
	else if (a >= 0 && a <= 59)
		std::cout << 'F';
	else;

	return 0;
}
