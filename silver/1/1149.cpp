#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

void dp(int n, std::vector<int>& r, std::vector<int>& g, std::vector<int>& b)
{
	std::vector<int> plan1;
	std::vector<int> plan2;
	std::vector<int> plan3;
	plan1.push_back(r[0]);
	plan2.push_back(g[0]);
	plan3.push_back(b[0]);
	if (n == 0) {
		std::vector<int> plans = { plan1[0], plan2[0], plan3[0] };
		std::cout << *std::min_element(plans.begin(), plans.end());
		return;
	}
	for (auto i = 1; i < n; ++i) {
		plan1.push_back(std::min(plan2[i - 1], plan3[i - 1]) + r[i]);
		plan2.push_back(std::min(plan1[i - 1], plan3[i - 1]) + g[i]);
		plan3.push_back(std::min(plan1[i - 1], plan2[i - 1]) + b[i]);
	}
	std::vector<int> plans = { plan1.back(), plan2.back(), plan3.back() };
	std::cout << *std::min_element(plans.begin(), plans.end());
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> cost_r;
	std::vector<int> cost_g;
	std::vector<int> cost_b;
	for (auto i = 0; i < n; ++i) {
		int x1 = 0;
		int x2 = 0;
		int x3 = 0;
		std::cin >> x1 >> x2 >> x3;
		cost_r.push_back(x1);
		cost_g.push_back(x2);
		cost_b.push_back(x3);
	}
	dp(n, cost_r, cost_g, cost_b);
}
