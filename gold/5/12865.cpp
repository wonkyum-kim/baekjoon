#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

int knapsack(std::vector<std::pair<int, int>>& stuff, int n, int W)
{
	std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= W; ++j) {
			if (j < stuff[i].first) {
				K[i][j] = K[i - 1][j];
			}
			else {
				K[i][j] = std::max(K[i - 1][j], K[i - 1][j - stuff[i].first] + stuff[i].second);
			}
		}
	}
	return K[n][W];
}

int main()
{
	int n = 0;
	int W = 0;
	std::cin >> n >> W;
	std::vector<std::pair<int, int>> stuff = { {0,0} };
	for (auto i = 0; i < n; ++i) {
		int weight = 0;
		int value = 0;
		std::cin >> weight >> value;
		stuff.push_back({ weight, value });
	}
	std::cout << knapsack(stuff, n, W);
}
