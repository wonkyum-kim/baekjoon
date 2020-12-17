#include <iostream>
#include <algorithm>
#include <vector>

int foo(std::vector<int>& A, int n)
{
	int ans = 0;
	std::vector<int> dp(n + 1);
	for (auto i = 1; i <= n; ++i) {
		dp[i] = A[i];
		for (auto j = 1; j < i; ++j) {
			if (A[j] < A[i] && dp[i] < dp[j] + A[i]) {
				dp[i] = dp[j] + A[i];
			}
		}
	}
	std::sort(dp.begin(), dp.end());
	return dp.back();
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> A(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> A[i];
	}
	std::cout << foo(A, n);
}
