#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> foo()
{
	std::vector<int> coins{ 1,2,3 };
	std::vector<int> dp(11);
	dp[0] = 1;
	for (auto i = 1; i <= 10; ++i) {
		for (const auto& c : coins) {
			if (i >= c) {
				dp[i] += dp[i - c];
			}
		}
	}
	return dp;
}

int main()
{
	int t = 0;
	std::cin >> t;
	auto dp = foo();
	for (auto i = 0; i < t; ++i) {
		int n = 0;
		std::cin >> n;
		std::cout << dp[n] << '\n';
	}
}
