#include <iostream>

constexpr int fac(long long int n)
{
	return n > 1 ? n * fac(n - 1) : 1;
}

int main()
{
	int n = 0;
	std::cin >> n;
	long long int result = fac(n);
	std::cout << result;
}
