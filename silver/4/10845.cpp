#include <iostream>
#include <queue>
#include <string>

int main()
{
	int test = 0;
	std::cin >> test;

	std::queue<int> q;

	for (int i = 0; i < test; ++i) {
		std::string s;
		std::cin >> s;

		if (s == "push") {
			int a = 0;
			std::cin >> a;
			q.push(a);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				std::cout << q.front() << '\n';
				q.pop();
			}
			else
				std::cout << -1 << '\n';
		}
		else if (s == "size") {
			std::cout << q.size() << '\n';
		}
		else if (s == "empty") {
			if (q.empty())
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if (s == "front") {
			if (q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty())
				std::cout << -1 << '\n';
			else
				std::cout << q.back() << '\n';
		}
	}
}
