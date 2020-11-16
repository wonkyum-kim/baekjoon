#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void n_cards(std::vector<int>& p, int n)
{
	if (n == 1) {
		std::cout << p[1];
		return;
	}
	else {
		std::vector<long long> dp(n + 1);
		for (auto i = 1; i <= n; ++i) {
			dp[i] = p[i];
		}
		for (auto i = 2; i <= n; ++i) {
			for (auto j = 0; j <= i / 2; ++j) {
				dp[i] = std::max(dp[i], dp[i - j] + dp[j]);
			}
		}
		std::cout << dp[n];
	}
}



int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> p(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> p[i];
	}
	n_cards(p, n);
}
