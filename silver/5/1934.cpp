#include <iostream>
#include <numeric>

int main()
{
	int test = 0;
	std::cin >> test;
	for (auto i = 0; i < test; ++i) {
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		std::cout << std::lcm(a, b) << '\n';
	}
}
