#include <queue>
#include <vector>
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::priority_queue<int> q;
	for (auto i = 0; i < n; ++i) {
		int x = 0;
		std::cin >> x;
		if (x != 0) {
			q.push(x);
		}
		else {
			if (q.empty()) {
				std::cout << "0\n";
			}
			else {
				std::cout << q.top() << '\n';
				q.pop();
			}
		}
	}
}
