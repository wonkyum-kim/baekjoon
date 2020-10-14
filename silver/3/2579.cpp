#include <iostream>
#include <vector>
#include <algorithm>

void dp(int n, std::vector<int>& stair)
{
	if (n == 1) {
		std::cout << stair[1];
		return;
	}
	else if (n == 2) {
		std::cout << stair[1] + stair[2];
		return;
	}
	std::vector<int> r(n + 1);
	r[1] = stair[1];
	r[2] = stair[1] + stair[2];
	r[3] = std::max(stair[1] + stair[3], stair[2] + stair[3]);
	for (auto i = 4; i <= n; ++i) {
		r[i] = std::max(r[i - 2] + stair[i], r[i - 3] + stair[i - 1] + stair[i]);
	}

	std::cout << r[n];
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> stair(n + 1);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> stair[i];
	}
	dp(n, stair);
}
