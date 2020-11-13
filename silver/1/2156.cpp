#include <vector>
#include <iostream>
#include <algorithm>

void drink(const std::vector<int>& wine, const int n)
{
	if (n == 1) {
		std::cout << wine[1];
		return;
	}
	else if (n == 2) {
		std::cout << wine[1] + wine[2];
		return;
	}
	else {
		std::vector<long long> dp(n + 1);
		dp[1] = wine[1];
		dp[2] = wine[1] + wine[2];
		for (auto i = 3; i <= n; ++i) {
			long long c1 = dp[i - 3] + wine[i - 1] + wine[i];
			long long c2 = dp[i - 2] + wine[i];
			long long c3 = dp[i - 1];
			c1 = std::max(c1, c2);
			c1 = std::max(c1, c3);
			dp[i] = c1;
		}
		std::cout << dp[n];
	}
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> wine{ 0 };
	for (auto i = 1; i <= n; ++i) {
		int w = 0;
		std::cin >> w;
		wine.push_back(w);
	}
	drink(wine, n);
}
