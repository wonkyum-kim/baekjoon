#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::pair<int, std::string>> v;

	int test = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		int a = 0;
		std::string b;
		std::cin >> a >> b;
		v.push_back({ a, b });
	}

	using ans = std::pair<int, std::string>;

	std::stable_sort(v.begin(), v.end(), [](const ans a, const ans b) {return a.first < b.first; });

	for (auto x : v)
		std::cout << x.first << ' ' << x.second << '\n';
}
