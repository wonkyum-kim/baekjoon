#include <iostream>
#include <vector>
#include <algorithm>

long long lis(std::vector<long long>& A, int n)
{
	std::vector<long long> L;
	for (auto i = 0; i < n; ++i) {
		if (L.empty() || L.back() < A[i]) {
			L.push_back(A[i]);
		}
		else {
			auto lower = std::lower_bound(L.begin(), L.end(), A[i]);
			auto idx = std::distance(L.begin(), lower);
			L[idx] = A[i];
		}
	}
	return L.size();
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
	std::cout << lis(A, n);
}
