#include <iostream>
#include <vector>
#include <algorithm>

void print_matrix(const std::vector<std::vector<int>>& C, const size_t n, const size_t m, const size_t k)
{
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < k; ++j) {
			std::cout << C[i][j] << ' ';
			if (j == k - 1) {
				std::cout << '\n';
			}
		}
	}
}

void matrix_multiply()
{
	int N = 0;
	int M = 0;
	int K = 0;

	std::cin >> N >> M;
	std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
	for (auto n = 0; n < N; ++n) {
		for (auto m = 0; m < M; ++m) {
			std::cin >> A[n][m];
		}
	}

	std::cin >> M >> K;
	std::vector<std::vector<int>> B(M, std::vector<int>(K,0));
	std::vector<std::vector<int>> C(N, std::vector<int>(K,0));
	for (auto m = 0; m < M; ++m) {
		for (auto k = 0; k < K; ++k) {
			std::cin >> B[m][k];
			for (auto n = 0; n < N; ++n) {
				C[n][k] += A[n][m] * B[m][k];
			}
		}
	}

	print_matrix(C, N, M, K);
}


int main()
{
	matrix_multiply();
}
