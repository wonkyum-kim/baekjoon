#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main()
{
	int test = 0;
	std::cin >> test;
	std::vector<std::tuple<int, int, int>> v;
	for (auto i = 0; i < test; ++i) {
		int weight = 0;
		int tall = 0;
		int count = 1;
		std::cin >> weight >> tall;
		v.push_back(std::make_tuple(weight,tall,count));
	}

	for (auto i = 0; i < v.size() - 1; ++i) {
		for (auto j = i + 1; j < v.size(); ++j) {
			auto [w1, t1, c1] = v[i];
			auto [w2, t2, c2] = v[j];
			if (w1 > w2 && t1 > t2) {
				v[j] = std::make_tuple(w2, t2, c2+1);
			}
			else if (w1 < w2 && t1 < t2) {
				v[i] = std::make_tuple(w1, t1, c1+1);
			}
		}
	}
	for (auto i = 0; i < v.size(); ++i) {
		auto [w, t, c] = v[i];
		std::cout << c << ' ';
	}
}
