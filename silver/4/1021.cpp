#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

int main()
{
	int n = 0;
	int m = 0;
	int result = 0;
	std::cin >> n >> m;
	std::vector<int> v;
	for (auto i = 1; i <= n; ++i) {
		v.push_back(i);
	}
	for (auto i = 0; i < m; ++i) {
		int x = 0;
		std::cin >> x;
		auto it = std::find(v.begin(), v.end(), x);
		result += std::min(it - v.begin(), v.end() - it);
		std::rotate(v.begin(), it, v.end());
		v.erase(v.begin());
	}
	std::cout << result;
}
