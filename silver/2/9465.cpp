#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

int main()
{
	int test = 0;
	std::cin >> test;
	for (auto i = 0; i < test; ++i) {
		int n = 0;
		std::cin >> n;
		std::vector<std::vector<long long>> sticker(2, std::vector<long long>(n + 1));
		for (auto j = 1; j <= n; ++j) {
			std::cin >> sticker[0][j];
		}
		for (auto j = 1; j <= n; ++j) {
			std::cin >> sticker[1][j];
		}
		std::vector<std::vector<long long>> dp(2, std::vector<long long>(n + 1));
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		for (auto k = 2; k <= n; ++k) {
			dp[0][k] = std::max(dp[1][k - 2], dp[1][k - 1]) + sticker[0][k];
			dp[1][k] = std::max(dp[0][k - 2], dp[0][k - 1]) + sticker[1][k];
		}
		std::cout << std::max(dp[0][n], dp[1][n]) << '\n';
	}
}
