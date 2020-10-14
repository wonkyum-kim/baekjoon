#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void dp(long long n)
{
	if (n == 1) {
		std::cout << 9;
		return;
	}
	std::vector<std::vector<long long>> stair(n + 1, std::vector<long long>(10));
	for (auto i = 1; i <= 9; ++i) {
		stair[1][i] = 1;
	}
	for (auto i = 2; i <= n; ++i) {
		for (auto j = 0; j <= 9; ++j) {
			if (j == 0) {
				stair[i][j] = stair[i - 1][j + 1] % 1'000'000'000;
			}
			else if (j == 9) {
				stair[i][j] = stair[i - 1][j - 1] % 1'000'000'000;
			}
			else {
				stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % 1'000'000'000;
			}
		}
	}
	long long result = 0;
	for (auto i = 0; i <= 9; ++i) {
		result += stair[n][i];
	}
	std::cout << result % 1'000'000'000;
}

int main()
{
	long long n = 0;
	std::cin >> n;
	dp(n);
}
