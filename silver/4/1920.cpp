#include <iostream>
#include <vector>
#include <algorithm>

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
	int m = 0;
	std::cin >> m;
	std::sort(v.begin(), v.end());
	for (auto i = 0; i < m; ++i) {
		int tag = 0;
		std::cin >> tag;
		if (std::binary_search(v.begin(), v.end(), tag)) {
			std::cout << "1" << '\n';
		}
		else {
			std::cout << "0" << '\n';
		}
	}
}
