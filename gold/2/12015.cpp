#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<long long> A(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> A[i];
	}
	std::vector<long long> L;

	for (auto i = 1; i <= n; ++i) {
		if (L.empty() || L.back() < A[i]) {
			L.push_back(A[i]);
		}
		else {
			auto lower = std::lower_bound(L.begin(), L.end(), A[i]);
			auto idx = std::distance(L.begin(), lower);
			L[idx] = A[i];
		}
	}

	std::cout << std::distance(L.begin(), L.end());
}
