#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::vector<std::pair<int, int>> v;
	for (auto i = 0; i < 11; ++i) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		v.push_back({ a, b });
	}

	std::sort(v.begin(), v.end());

	int sum = 0;
	int result = 0;

	for (auto j = 0; j < 11; ++j) {
		sum += v[j].first;
		result += sum + v[j].second * 20;
	}

	std::cout << result;
}
