#include <iostream>
#include <algorithm>

int check_count(const char arr[][50], const int n) {
	int max_count = 1;
	// 행 단위 검사
	for (int i = 0; i < n; i++) {
		int running_sum = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				running_sum++;
				max_count = std::max(max_count, running_sum);
			}
			else {
				max_count = std::max(max_count, running_sum);
				running_sum = 1;
			}
		}
	}
	// 열 단위 검사
	for (int i = 0; i < n; i++) {
		int running_sum = 1;
		for (int j = 1; j < n; j++) {
			if (arr[j][i] == arr[j - 1][i]) {
				running_sum++;
				max_count = std::max(max_count, running_sum);
			}
			else {
				max_count = std::max(max_count, running_sum);
				running_sum = 1;
			}
		}
	}
	return max_count;
}

int main()
{
	int n = 0;
	std::cin >> n;

	char arr[50][50];
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			std::cin >> arr[i][j];
		}
	}

	int result = std::numeric_limits<int>::min();

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n - 1; ++j) {
			// 오른쪽 교환 후 원상 복구
			std::swap(arr[i][j], arr[i][j + 1]);
			result = std::max(check_count(arr, n), result);
			std::swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for (auto i = 0; i < n - 1; ++i) {
		for (auto j = 0; j < n; ++j) {
			// 아래쪽 교환 후 원상 복구
			std::swap(arr[i][j], arr[i + 1][j]);
			result = std::max(check_count(arr, n), result);
			std::swap(arr[i][j], arr[i + 1][j]);
		}
	}

	std::cout << result;
}
