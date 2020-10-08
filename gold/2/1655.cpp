#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::priority_queue<int> max;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min;
	int mid = 0;

	int n = 0;
	std::cin >> n;
	for (auto i = 1; i <= n; ++i) {
		int x = 0;
		std::cin >> x;

		if (i == 1) {
			mid = x;
			std::cout << mid << '\n';
		}
		else if (i == 2) {
			min.push(std::max(x, mid));
			max.push(std::min(x, mid));
			mid = 0;
			std::cout << max.top() << '\n';
		}
		else if (i != 1 && i % 2 != 0) {
			if (x > min.top()) {
				min.push(x);
				mid = min.top();
				min.pop();
			}
			else {
				if (x >= max.top()) {
					mid = x;
				}
				else {
					max.push(x);
					mid = max.top();
					max.pop();
				}
			}
			std::cout << mid << '\n';
		}
		else if (i != 2 && i % 2 == 0) {
			if (x > mid) {
				min.push(x);
				max.push(mid);
			}
			else {
				max.push(x);
				min.push(mid);
			}
			mid = 0;
			std::cout << max.top() << '\n';
		}
	}
}
