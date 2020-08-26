#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	int n = 0;	// 종류
	int k = 0;	// 합
	std::cin >> n >> k;

	std::vector<int> coin;
	for (auto i = 0; i < n; ++i) {
		int a = 0;
		std::cin >> a;
		coin.push_back(a);
	}

	int count = 0;
	if (coin.size() >= 1) {
		for (int j = coin.size() - 1; j >= 0; --j) {
			int a = k / coin[j];
			k -= a * coin[j];
			count += a;
		}
	}

	std::cout << count;
}
