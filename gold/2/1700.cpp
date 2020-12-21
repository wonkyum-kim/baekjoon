#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

int greedy(std::vector<int>& order, int n, int k)
{
	int count = 0;
	std::vector<int> tab;
	for (auto i = 0; i < k; ++i) {
		if (tab.empty() || std::find(tab.begin(), tab.end(), order[i]) == tab.end()) {
			tab.push_back(order[i]);
			count = i;
		}
		if (tab.size() == n) {
			break;
		}
	}

	int plug = 0;
	for (auto j = count + 1; j < k; ++j) {
		if (std::find(tab.begin(), tab.end(), order[j]) != tab.end()) {
			// do not anything.
		}
		else {
			std::vector<int> how_far;
			for (auto s = 0; s < n; ++s) {
				auto it = std::find(order.begin() + j, order.end(), tab[s]);
				int dis = 100;
				if (it != order.end()) {
					dis = std::distance(order.begin() + j, it);
				}
				how_far.push_back(dis);
			}
			auto far = std::max_element(how_far.begin(), how_far.end());
			int idx = std::distance(how_far.begin(), far);
			tab[idx] = order[j];
			plug++;
		}
	}
	return plug;
}


int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	std::vector<int> order(k);
	for (auto i = 0; i < k; ++i) {
		std::cin >> order[i];
	}
	std::cout << greedy(order, n, k);
}
