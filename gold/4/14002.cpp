#include <vector>
#include <iostream>
#include <algorithm>

void backtrace(int n, int length, std::vector<long long>& P, std::vector<long long>& A)
{
	if (n == 0) {
		return;
	}
	if (P[n] == length) {
		backtrace(n - 1, length - 1, P, A);
		std::cout << A[n] << ' ';
	}
	else {
		backtrace(n - 1, length, P, A);
	}
}


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<long long> A(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> A[i];
	}
	std::vector<long long> L;
	std::vector<long long> P(n + 1);

	for (auto i = 1; i <= n; ++i) {
		if (L.empty() || L.back() < A[i]) {
			L.push_back(A[i]);
			P[i] = L.size();
		}
		else {
			auto lower = std::lower_bound(L.begin(), L.end(), A[i]);
			auto idx = std::distance(L.begin(), lower);
			L[idx] = A[i];
			P[i] = std::distance(L.begin(), lower) + 1;
		}
	}

	std::cout << L.size() << '\n';
	backtrace(n, L.size(), P, A);
}
	
