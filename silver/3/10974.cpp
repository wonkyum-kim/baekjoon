#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<int> per;
	for (auto i = 1; i <= N; ++i) {
		per.push_back(i);
	}

	for (auto x : per) {
		std::cout << x << ' ';
	}

	std::cout << '\n';

	while (true) {
		if (std::next_permutation(per.begin(), per.end())) {
			for (auto x : per) {
				std::cout << x << ' ';
			}
			std::cout << '\n';
		}
		else {
			break;
		}
	}
}
