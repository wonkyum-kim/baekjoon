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
		std::cout << 2;
		return;
	}
	else {
		std::vector<long long> dp(n + 1,std::numeric_limits<int>::max());
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (long long i = 1; i <= n; ++i) {
			if (i * i <= n) {
				dp[i*i] = 1;
			}
		}

		for (long long i = 3; i <= n; ++i) {
			for (long long j = 0; j <= i; ++j) {
				if (j * j <= i) {
					dp[i] = std::min(dp[i], dp[j * j] + dp[i - j * j]);
				}
				else {
					break;
				}
			}
		}
		std::cout << dp[n];
		return;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	long long n = 0;
	std::cin >> n;
	tile(n);
}
