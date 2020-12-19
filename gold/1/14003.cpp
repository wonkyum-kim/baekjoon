#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

std::pair<long long, std::vector<long long>> lis(std::vector<long long>& A, int n)
{
	std::vector<long long> L;
	std::vector<long long> P(n);
	for (auto i = 0; i < n; ++i) {
		if (L.empty() || L.back() < A[i]) {
			L.push_back(A[i]);
			P[i] = L.size();
		}
		else {
			auto lower = std::lower_bound(L.begin(), L.end(), A[i]);
			auto idx = std::distance(L.begin(), lower);
			L[idx] = A[i];
			P[i] = idx + 1;
		}
	}
	return { L.size(), P };
}

void print_lis(long long length, std::vector<long long>& dp, std::vector<long long>& A)
{
	std::stack<long long> s;
	for (long long i = dp.size() - 1; i >= 0; --i) {
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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<long long> A(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	auto [a, b] = lis(A, n);
	std::cout << a << '\n';
	print_lis(a, b, A);
}
