#include <vector>
#include <iostream>
#include <algorithm>


size_t fibonacci(const size_t n)
{
	std::vector<size_t> f(n + 1);
	if (n == 0) {
		return 0;
	}
	else if (n == 1 || n == 2) {
		return 1;
	}
	else {
		f[0] = 0;
		f[1] = 1;
		f[2] = 1;
		for (auto i = 3; i <= n; ++i) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
}

int main()
{
	size_t n = 0;
	std::cin >> n;
	std::cout << fibonacci(n);
}
