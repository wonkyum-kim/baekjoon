#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>


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

	std::vector<std::vector<int>> elec(n + 1, std::vector<int>(2));
	for (auto i = 1; i <= n; ++i) {
		std::cin >> elec[i][0] >> elec[i][1];
	}
	std::sort(elec.begin(), elec.end());
	
	std::vector<long long> B(n + 2);
	for (auto i = 1; i <= n; ++i) {
		B[i] = elec[i][1];
	}

	auto temp1 = n - length_of_lis(n, B);
	auto temp2 = n - length_of_lds(1, B);
	std::cout << temp1;
}
