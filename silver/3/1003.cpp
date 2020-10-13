#include <vector>
#include <iostream>
#include <algorithm>

void dp(int n)
{
	std::vector<int> c0(n + 1);
	std::vector<int> c1(n + 1);
	c0[0] = 1;
	c1[0] = 0;
	if (n == 1) {
		c0[1] = 0;
		c1[1] = 1;
	}
	else if (n >= 2) {
		c0[1] = 0;
		c1[1] = 1;
		for (auto i = 2; i <= n; ++i) {
			c0[i] = c0[i - 1] + c0[i - 2];
			c1[i] = c1[i - 1] + c1[i - 2];
		}
	}
	std::cout << c0[n] << ' ' << c1[n] << '\n';
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
