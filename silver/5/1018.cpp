#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

int re_paint(const std::vector<std::vector<char>>& chess, const size_t x, const size_t y)
{
	int count1 = 0, count2 = 0;

	for (auto i = x; i < x + 8; ++i) {
		for (auto j = y; j < y + 8; ++j) {

			// first case : first cell is black.
			// BWBWBW...
			if ((i + j) % 2 == 0 && chess[i][j] == 'W') {
				count1++;
			}
			else if ((i + j) % 2 == 1 && chess[i][j] == 'B') {
				count1++;
			}

			// second case : first cell is white.
			// WBWBWB...
			if ((i + j) % 2 == 0 && chess[i][j] == 'B') {
				count2++;
			}
			else if ((i + j) % 2 == 1 && chess[i][j] == 'W') {
				count2++;
			}
		}
	}
	return std::min(count1, count2);
}

int main()
{
	int N = 0, M = 0;
	std::cin >> N >> M;

	std::vector<std::vector<char>> chess(N + 1, std::vector<char>(M + 1));
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= M; ++j) {
			std::cin >> chess[i][j];
		}
	}

	int min_value = std::numeric_limits<int>::max();

	for (auto i = 1; i <= N - 7; ++i) {
		for (auto j = 1; j <= M - 7; ++j) {
			if (min_value > re_paint(chess, i, j)) {
				min_value = re_paint(chess, i, j);
			}
		}
	}

	std::cout << min_value;
}
