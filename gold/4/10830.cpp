#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template<typename T>
std::vector<std::vector<T>> matrix_multiply(const std::vector<std::vector<T>>& A, const std::vector<std::vector<T>>& B)
{
	// row 0 & column 0 are empty.
	assert(A[1].size() == B.size());
	std::vector<std::vector<T>> C(A.size(), std::vector<T>(B[1].size()));
	for (auto i = 1; i < A.size(); ++i) {
		for (auto j = 1; j < B[1].size(); ++j) {
			for (auto k = 1; k < A[1].size(); ++k) {
				C[i][j] += (A[i][k]) * (B[k][j])%1000;
			}
			C[i][j] %= 1000;
		}
	}
	return C;
}

template<typename T>
std::vector<std::vector<T>> matrix_pow(const std::vector<std::vector<T>>& A, const long long m)
{
	// base case
	if (m == 0) {
		std::vector<std::vector<T>> identity(A.size(), std::vector<T>(A.size()));
		for (auto i = 1; i < A.size(); ++i) {
			for (auto j = 1; j < A.size(); ++j) {
				if (i == j) {
					identity[i][j] = 1;
				}
			}
		}
		return identity;
	}

	if (m % 2 == 1) {
		return matrix_multiply(matrix_pow(A, m - 1), A);
	}

	auto temp = matrix_pow(A, m / 2);
	return matrix_multiply(temp, temp);
	
}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n = 0;
	long long b = 0;
	std::cin >> n >> b;
	std::vector<std::vector<long long>> A(n + 1, std::vector<long long>(n + 1));
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= n; ++j) {
			std::cin >> A[i][j];
		}
	}

	auto C = matrix_pow(A, b);
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= n; ++j) {
			std::cout << C[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
