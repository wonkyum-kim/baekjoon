#include <queue>
#include <vector>
#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;

	auto cmp = [](int a, int b) {
		if (std::abs(a) == std::abs(b)) {
			return a > b;
		}
		else {
			return std::abs(a) > std::abs(b);
		}
	};

	std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
	for (auto i = 0; i < n; ++i) {
		int x = 0;
		std::cin >> x;
		if (x == 0 && q.empty()) {
			std::cout << '0' << '\n';
		}
		else if (x == 0 && !q.empty()) {
			std::cout << q.top() << '\n';
			q.pop();
		}
		else {
			q.push(x);
		}
	}
}
