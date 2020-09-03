#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int adjacent_count(const std::vector<std::vector<char>>& candy, const int N)
{
	int max_count = 1;

	// 행 단위 검사
	for (auto i = 1; i <= N; ++i) {
		int running_count = 1;
		for (auto j = 2; j <= N; ++j) {
			if (candy[i][j] == candy[i][j - 1]) {
				running_count++;
				max_count = std::max(running_count, max_count);
			}
			else {
				max_count = std::max(running_count, max_count);
				running_count = 1;
			}
		}
	}

	// 열 단위 검사
	for (auto i = 1; i <= N; ++i) {
		int running_count = 1;
		for (auto j = 2; j <= N; ++j) {
			if (candy[j][i] == candy[j - 1][i]) {
				running_count++;
				max_count = std::max(running_count, max_count);
			}
			else {
				max_count = std::max(running_count, max_count);
				running_count = 1;
			}
		}
	}

	return max_count;
}

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<std::vector<char>> candy(N + 1, std::vector<char>(N + 1));
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= N; ++j) {
			std::cin >> candy[i][j];
		}
	}

	int result = std::numeric_limits<int>::min();

	// 오른쪽 교환 이후 원상 복구
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= N - 1; ++j) {
			std::swap(candy[i][j], candy[i][j + 1]);
			result = std::max(result, adjacent_count(candy, N));
			std::swap(candy[i][j], candy[i][j + 1]);
		}
	}

	// 아래쪽 교환 이후 원상 복구
	for (auto i = 1; i <= N - 1; ++i) {
		for (auto j = 1; j <= N; ++j) {
			std::swap(candy[i][j], candy[i + 1][j]);
			result = std::max(result, adjacent_count(candy, N));
			std::swap(candy[i][j], candy[i + 1][j]);
		}
	}

	std::cout << result;
}
