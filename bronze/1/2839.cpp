#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> dp(5001, 9999);
	dp[3] = 1;
	dp[5] = 1;
	for (auto i = 6; i <= n; ++i) {
		dp[i] = std::min(dp[i - 3], dp[i - 5]) + 1;
	}
	if (dp[n] == 9999 || dp[n] == 10000) {
		std::cout << -1;
	}
	else {
		std::cout << dp[n];
	}
}
