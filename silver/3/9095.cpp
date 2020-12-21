#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> foo()
{
	std::vector<int> dp(12);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (auto i = 4; i < 12; ++i) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
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
		std::cout << dp[n] <<'\n';
	}
}
