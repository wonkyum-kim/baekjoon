#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

std::vector<int> lis(std::vector<int>& A, int n)
{
	std::vector<int> dp(n, 1);
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < i; ++j) {
			if (A[j] < A[i]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp;
}

void print_lis(int length, std::vector<int>& dp, std::vector<int>& A)
{
	std::stack<int> s;
	for (int i = dp.size() - 1; i >= 0; --i) {
		if (dp[i] == length) {
			s.push(A[i]);
			length--;
			if (length == 0) {
				break;
			}
		}
	}
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> A(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> A[i];
	}

	auto dp = lis(A, n);
	int length = *std::max_element(dp.begin(), dp.end());
	std::cout << length << '\n';
	print_lis(length, dp, A);
}
