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
		int data = 0;
		std::cin >> data;
		per.push_back(data);
	}

	if (std::next_permutation(per.begin(), per.end())) {
		for (auto x : per) {
			std::cout << x << ' ';
		}
	}
	else {
		std::cout << -1;
	}
		
}
