#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int test = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		std::priority_queue<int> max;
		std::priority_queue<int, std::vector<int>, std::greater<int>> min;
		std::vector<int> v;
		int mid = 0;

		int m = 0;
		std::cin >> m;
		std::cout << (m + 1) / 2 << '\n';

		for (auto j = 1; j <= m; ++j) {
			int x = 0;
			std::cin >> x;

			if (j == 1) {
				mid = x;
				v.push_back(mid);
			}
			else if (j == 2) {
				min.push(std::max(x, mid));
				max.push(std::min(x, mid));
				mid = 0;
			}
			else if (j != 1 && j % 2 != 0) {
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
				v.push_back(mid);
			}
			else if (j != 2 && j % 2 == 0) {
				if (x > mid) {
					min.push(x);
					max.push(mid);
				}
				else {
					max.push(x);
					min.push(mid);
				}
				mid = 0;
			}
		}
		for (auto k = 1; k <= v.size(); ++k) {
			std::cout << v[k - 1] << ' ';
			if (k % 10 == 0) {
				std::cout << '\n';
			}
		}
		std::cout << '\n';
	}
}
