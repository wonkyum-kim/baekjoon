#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void dp(std::vector<int>& coin, int n, int k)
{
	std::vector<long long> won(k + 1, std::numeric_limits<int>::max());

	// 동전의 가치가 k와 같다면 최소 개수는 1
	for (auto i = 1; i <= n; ++i) {
		if (coin[i] <= k) {
			won[coin[i]] = 1;
		}
	}

	for (auto i = 1; i <= k; ++i) {
		for (auto j = 1; j <= i / 2; ++j) {
			won[i] = std::min(won[i], won[j] + won[i - j]);
		}
	}

	if (won[k] == std::numeric_limits<int>::max()) {
		std::cout << -1;
	}
	else {
		std::cout << won[k];
	}
}

int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	std::vector<int> coin(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> coin[i];
	}
	dp(coin, n, k);
}
