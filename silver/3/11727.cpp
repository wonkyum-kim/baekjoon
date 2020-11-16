#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void tile(int n)
{
	if (n == 1) {
		std::cout << 1;
		return;
	}
	else if (n == 2) {
		std::cout << 3;
		return;
	}
	else {
		std::vector<long long> dp(n + 1);
		dp[1] = 1;
		dp[2] = 3;
		for (auto i = 3; i <= n; ++i) {
			dp[i] = dp[i - 2] % 10'007 + dp[i - 1] % 10'007 + dp[i - 2] % 10'007;
			dp[i]%= 10'007;
		}
		std::cout << dp[n]%10'007;

	}
}

int main()
{
	int n = 0;
	std::cin >> n;
	tile(n);
}
