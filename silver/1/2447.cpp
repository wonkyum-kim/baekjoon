#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void star(std::vector<std::vector<char>>& A, long long N, const int x, const int y)
{
	if (N == 3) {
		A[x][y] = '*';
		A[x][y + 1] = '*';
		A[x][y + 2] = '*';
		A[x + 1][y] = '*';
		A[x + 1][y + 2] = '*';
		A[x + 2][y] = '*';
		A[x + 2][y + 1] = '*';
		A[x + 2][y + 2] = '*';
		return;
	}

	star(A, N / 3, x, y);
	star(A, N / 3, x, y + N / 3);
	star(A, N / 3, x, y + 2 * N / 3);

	star(A, N / 3, x + N / 3, y);
	star(A, N / 3, x + N / 3, y + 2 * N / 3);

	star(A, N / 3, x + 2 * N / 3, y);
	star(A, N / 3, x + 2 * N / 3, y + N / 3);
	star(A, N / 3, x + 2 * N / 3, y + 2 * N / 3);
}

int main()
{
	long long N = 0;
	std::cin >> N;
	std::vector<std::vector<char>> A(N, std::vector<char>(N, ' '));

	star(A, N, 0, 0);

	for (auto i = 0; i < N; ++i) {
		for (auto j = 0; j < N; ++j) {
			std::cout << A[i][j];
		}
		std::cout << '\n';
	}
}
