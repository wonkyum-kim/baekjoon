#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<int> v;
	for (auto i = 0; i < n; ++i) {
		int temp = 0;
		std::cin >> temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());

	int m = 0;
	std::cin >> m;
	for (auto i = 0; i < m; ++i) {
		int temp = 0;
		std::cin >> temp;
		auto p = std::equal_range(v.begin(), v.end(), temp);
		std::cout << p.second - p.first << ' ';
	}
}
