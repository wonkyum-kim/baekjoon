#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<size_t> budget;
	for (auto i = 0; i < n; ++i) {
		size_t temp = 0;
		std::cin >> temp;
		budget.push_back(temp);
	}

	size_t low = 0;
	size_t high = *std::max_element(budget.begin(), budget.end());
	size_t mid = 0;
	size_t result = 0;

	size_t max_budget = 0;
	std::cin >> max_budget;

	while (low <= high) {
		mid = (low + high) / 2;
		size_t sum = 0;
		for (auto x : budget) {
			sum += std::min(x, mid);
		}
		if (sum > max_budget) {
			high = mid - 1;
		}
		else if (sum < max_budget) {
			low = mid + 1;
			result = mid;
		}
		else {
			result = mid;
			break;
		}
	}
	std::cout << result;
}
