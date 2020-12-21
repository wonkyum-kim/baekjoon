#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 14501

int foo(std::vector<std::vector<int>>& coun, int n)
{
	std::vector<int> dp(n + 2);
	for (int i = n; i >= 1; --i) {
		if (i + coun[i][0] > n + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = std::max(dp[i + 1], dp[i + coun[i][0]] + coun[i][1]);
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::vector<int>> coun(n + 1, std::vector<int>(2));
	for (auto i = 1; i <= n; ++i) {
		std::cin >> coun[i][0] >> coun[i][1];
	}
	std::cout << foo(coun, n);
}
