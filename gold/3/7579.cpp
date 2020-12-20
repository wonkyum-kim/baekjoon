#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

long long foo(std::vector<long long>& memory, std::vector<long long>& cost, int N, int M)
{
	std::vector<std::vector<long long>> dp (N + 1, std::vector<long long>(10001));
	std::vector<long long> K;
	for (auto i = 1; i <= N; ++i) {
		for (auto j = 1; j <= 10000; ++j) {
			if (j < cost[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			if (dp[i][j] >= M) {
				K.push_back(j);
			}
		}
	}
	return *std::min_element(K.begin(), K.end());
}

int main()
{
	int N = 0;
	int M = 0;
	std::cin >> N >> M;
	std::vector<long long> memory{ 0 };
	std::vector<long long> cost{ 0 };
	for (auto i = 0; i < N; ++i) {
		long long m = 0;
		std::cin >> m;
		memory.push_back(m);
	}
	for (auto i = 0; i < N; ++i) {
		long long c = 0;
		std::cin >> c;
		cost.push_back(c);
	}

	std::cout << foo(memory, cost,N, M);
}
