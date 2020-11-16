#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void climing(int n, std::vector<std::vector<long long>>& dp)
{
	for (auto i = 0; i <= 9; ++i) {
		dp[1][i] = 1;
	}
	if (n > 1) {
		for (auto i = 2; i <= n; ++i) {
			for (auto j = 0; j <= 9; ++j) {
				for (auto k = 0; k <= j; ++k) {
					dp[i][j] += dp[i - 1][k];
				}
				dp[i][j] %= 10'007;
			}
		}
	}
	std::cout << std::accumulate(dp[n].begin(), dp[n].end(), 0)% 10'007;;
	
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(10));
	climing(n, dp);
}
