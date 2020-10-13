#include <vector>
#include <iostream>
#include <algorithm>

void dp(int n)
{
	std::vector<long long> p(n + 1);
	if (n <= 3) {
		std::cout << 1 << '\n';
	}
	else {
		p[1] = 1;
		p[2] = 1;
		p[3] = 1;
		for (auto i = 4; i <= n; ++i) {
			p[i] = p[i - 2] + p[i - 3];
		}
		std::cout << p[n] << '\n';
	}
}

int main()
{
	int t = 0;
	std::cin >> t;
	for (auto i = 0; i < t; ++i) {
		int n = 0;
		std::cin >> n;
		dp(n);
	}
}
