#include <iostream>
#include <utility>
#include <deque>

int main()
{
	int N = 0;
	std::cin >> N;
	std::deque<std::pair<int, int>> dq;

	for (auto i = 1; i <= N; ++i) {
		int temp = 0;
		std::cin >> temp;
		dq.push_back({ temp, i });
	}

	while (true) {
		if (dq.empty()) {
			break;
		}
		else {
			std::pair<int, int> ballon = dq.front();
			std::cout << ballon.second << ' ';
			dq.pop_front();

			// shift left
			if (ballon.first > 0) {
				for (auto i = 1; i < ballon.first; ++i) {
					if (!dq.empty()) {
						std::pair<int, int> temp = dq.front();
						dq.pop_front();
						dq.push_back(temp);
					}
				}
				if (!dq.empty()) {
					ballon = dq.front();
				}
			}
			// shift right
			else {
				for (auto i = 1; i <= -1 * ballon.first; ++i) {
					if (!dq.empty()) {
						std::pair<int, int> temp = dq.back();
						dq.pop_back();
						dq.push_front(temp);
					}
				}
				if (!dq.empty()) {
					ballon = dq.front();
				}
			}
		}
	}
}
