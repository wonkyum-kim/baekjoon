#include <vector>
#include <iostream>
#include <algorithm>


long long fibonacci(const long long n)
{
	std::vector<long long> f(n + 1);
	if (n == 0) {
		return 0;
	}
	else if (n == 1 || n == 2) {
		return 1;
	}
	else {
		f[0] = 0;
		f[1] = 1;
		for (auto i = 2; i <= n; ++i) {
			f[i] = f[i - 1] + f[i - 2];
			f[i] %= 1'000'000;
		}
		return f[n % 1'500'000];
	}
}

int main()
{
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci(n % 1'500'000);
}
