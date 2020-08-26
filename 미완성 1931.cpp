#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::pair<long long, long long>> v;

	for (auto i = 0; i < n; ++i) {
		long long a = 0, b = 0;
		std::cin >> a >> b;
		v.push_back({ a, b });
	}

	std::sort(v.begin(), v.end(), [](std::pair<long long, long long> a, std::pair<long long, long long> b) {return a.second != b.second ? a.second < b.second : a.first < b.first; });


	std::cout << '\n';
	for (auto x : v) {
		std::cout << x.first << ' ' << x.second << '\n';
	}


	size_t i = 1, j = 0;
	int count = 1;

	while(true) {
		if (v[i++].first >= v[j].second) {
			count++;
			j = i;
		}
		if (i == v.size()) {
			break;
		}
	}

	std::cout << count;
}

/*
반례
7
11 13
21 23
31 33
2 12
12 22
22 32
32 42
*/
