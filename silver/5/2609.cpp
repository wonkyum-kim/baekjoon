#include <iostream>
#include <numeric>

int main()
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	std::cout << std::gcd(a, b) << '\n' << std::lcm(a, b);
}
