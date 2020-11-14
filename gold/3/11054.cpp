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

long long length_of_lds(int k, std::vector<long long>& A)
{
	std::vector<long long> L;

	for (auto i = A.size() - 2; i >= k; --i) {
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
	std::vector<long long> A(n + 2);

	for (auto i = 1; i <= n; ++i) {
		std::cin >> A[i];
	}
	
	long long max = 0;

	for (auto i = 1; i <= n; ++i) {
		auto temp = length_of_lis(i, A) + length_of_lds(i, A) - 1;
		max = std::max(max, temp);
	}
	std::cout << max;
}
