#include <iostream>
#include <algorithm>
#include <vector>

int lis(std::vector<int>& A, int n)
{
	std::vector<int> dp(n, 1);
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < i; ++j) {
			if (A[j] < A[i]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> A(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	std::cout << lis(A, n);
}
