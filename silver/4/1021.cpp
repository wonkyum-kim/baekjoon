#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

void fill_deque(const int N, std::deque<int>& dq) 
{
	for (auto i = 1; i <= N; ++i) {
		dq.push_back(i);
	}
}

void fill_keys(const int M, std::vector<int>& key)
{
	for (auto i = 0; i < M; ++i) {
		int index = 0;
		std::cin >> index;
		key.push_back(index);
	}
}

int main()
{
	int N = 0;
	int M = 0;
	std::cin >> N >> M;

	std::deque<int> dq;
	fill_deque(N, dq);

	std::vector<int> key;
	fill_keys(M, key);

	size_t min_count = 0;

	for (auto i = 0; i < M; ++i) {
		size_t count_left = 0;
		size_t count_right = 0;

		if (dq.front() == key[i]) {
			dq.pop_front();
		}
		else {
			std::deque<int> temp_left = dq;
			// shift left.
			while (true) {
				int not_key = temp_left.front();
				temp_left.pop_front();
				temp_left.push_back(not_key);
				count_left++;
				if (temp_left.front() == key[i]) {
					temp_left.pop_front();
					break;
				}
			}
			std::deque<int> temp_right = dq;
			// shift right.
			while (true) {
				int not_key = temp_right.back();
				temp_right.pop_back();
				temp_right.push_front(not_key);
				count_right++;
				if (temp_right.front() == key[i]) {
					temp_right.pop_front();
					break;
				}
			}
			min_count += std::min(count_left, count_right);
			if (count_left < count_right) {
				dq = temp_left;
				temp_right = dq;
			}
			else {
				dq = temp_right;
				temp_left = dq;
			}
		}
	}
	std::cout << min_count;
}
