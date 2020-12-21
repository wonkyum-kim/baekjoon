#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

int greedy(std::vector<std::pair<int, int>>& schedule, int n)
{
	std::sort(schedule.begin(), schedule.end());
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(schedule[0].second);
	for (auto i = 1; i < n; ++i) {
		if (pq.top() > schedule[i].first) {
			pq.push(schedule[i].second);
		}
		else {
			pq.pop();
			pq.push(schedule[i].second);
		}
	}
	return pq.size();
}


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::pair<int, int>> schedule;
	for (auto i = 0; i < n; ++i) {
		int s = 0;
		int t = 0;
		std::cin >> s >> t;
		schedule.push_back({ s,t });
	}
	std::cout << greedy(schedule, n);
}
