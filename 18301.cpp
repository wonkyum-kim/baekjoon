#include <iostream>
#include <cmath>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	int d = a + 1;
	int e = b + 1;
	int f = c + 1;

	auto x = d * e / f - 1;
	std::cout << std::floor(x);
}
