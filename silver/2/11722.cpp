#include <vector>
#include <iostream>
#include <algorithm>


long long length_of_lis(int n, std::vector<long long>& A)
{
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
	return L.size();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<long long> A(n + 1);
	// 1 5 2 1 4 3 4 5 2 1

	for (auto i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	std::reverse(A.begin(), A.end());;
	
	std::cout << length_of_lis(n, A);
}
