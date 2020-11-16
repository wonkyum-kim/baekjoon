#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void binomial(int n, int k)
{
	if (k == 0 || n == k) {
		std::cout << 1;
		return;
	}
	else if (k == 1) {
		std::cout << n;
		return;
	}
	else {
		std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1));
		for (auto i = 1; i <= n; ++i) {
			dp[i][0] = 1;
			dp[i][i] = 1;
		}
		for (auto i = 2; i <= n; ++i) {
			for (auto j = 1; j < n; ++j) {
				dp[i][j] = dp[i - 1][j - 1]%10'007 + dp[i - 1][j] % 10'007;
				dp[i][j] %= 10'007;
			}
		}
		std::cout << dp[n][k];
	}
}

int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	binomial(n, k);
}
