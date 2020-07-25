#include <iostream>

int main()
{
	auto a = 0, b = 0;
	std::cin >> a >> b;

	int b100 = b / 100;
	int b1 = b % 10;
 	int b10 = ((b - b1) / 10) % 10;

	int x1 = a * b1;
	int x2 = a * b10;
	int x3 = a * b100;
	int x4 = a * b;

	cout << x1 << '\n' << x2 << '\n' << x3 << '\n' << x4;
	return 0;
}
