#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int main()
{
	std::queue<int> q;
	int n = 0, k = 0;
	std::cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	std::vector<int> v;

	while (true) {
		if (!q.empty()) {
			for (int i = 1; i <= k - 1; ++i) {
				int a = q.front();
				q.pop();
				q.push(a);
			}

			int c = q.front();
			q.pop();
			v.push_back(c);

			if (q.empty()) {
				break;
			}
		}
	}

	std::cout << "<";
	for (int i = 0; i < v.size() - 1; ++i) {
		std::cout << v[i] << ", ";
	}
	std::cout << v[v.size() - 1] << '>';
}
