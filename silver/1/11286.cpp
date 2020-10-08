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
	
	// min priority queue
	std::priority_queue<int, std::vector<int>, std::greater<int>> plus;
	// max priority queue
	std::priority_queue<int> minus;

	for (auto i = 0; i < n; ++i) {
		int x = 0;
		std::cin >> x;
		if (x == 0 && plus.empty() && minus.empty()) {
			std::cout << "0\n";
		}
		else if (x == 0 && plus.empty() && !minus.empty()) {
			std::cout << minus.top() << '\n';
			minus.pop();
		}
		else if (x == 0 && !plus.empty() && minus.empty()) {
			std::cout << plus.top() << '\n';
			plus.pop();
		}
		else if (x == 0 && !plus.empty() && !minus.empty()) {
			if (std::abs(minus.top()) > plus.top()) {
				std::cout << plus.top() << '\n';
				plus.pop();
			}
			else {
				std::cout << minus.top() << '\n';
				minus.pop();
			}
		}
		else if (x < 0) {
			minus.push(x);
		}
		else if (x > 0) {
			plus.push(x);
		}
	}
}
