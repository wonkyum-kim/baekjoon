#include <iostream>
#include <string>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int a1 = a % 10;
	int a10 = ((a - a % 10) / 10) % 10;
	int a100 = a / 100;

	int b1 = b % 10;
	int b10 = ((b - b % 10) / 10) % 10;
	int b100 = b / 100;

	int new_a = a1 * 100 + a10 * 10 + a100;
	int new_b = b1 * 100 + b10 * 10 + b100;

	if (new_a > new_b)
		std::cout << new_a;
	else
		std::cout << new_b;
}
