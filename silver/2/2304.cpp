#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>


void make_roof(std::vector<std::pair<int, int>>& pole)
{
	// 좌표 기준으로 정렬
	std::sort(pole.begin(), pole.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.first < b.first; });

	std::stack<std::pair<int, int>> left;
	std::stack<std::pair<int, int>> right;

	// 왼쪽 부터 큰 기둥 찾기
	for (auto i = 0; i < pole.size(); ++i) {
		if (left.empty()) {
			left.push(pole[i]);
		}
		else {
			if (left.top().second < pole[i].second) {
				left.push(pole[i]);
			}
		}
	}
	// 오른쪽 부터 큰 기둥 찾기
	for (int i = pole.size() - 1; i >= 0; --i) {
		if (right.empty()) {
			right.push(pole[i]);
		}
		else {
			if (right.top().second < pole[i].second) {
				right.push(pole[i]);
			}
		}
	}

	// 가장 큰 기둥이 차지하는 면적
	int area = 0;
	area += (right.top().first - left.top().first + 1) * left.top().second;

	// 왼쪽 부분이 차지하는 면적
	while (left.size() > 1) {
		int a = left.top().first;
		left.pop();
		area += (a - left.top().first) * left.top().second;
	}
	// 오른쪽 부분이 차지하는 면적
	while (right.size() > 1) {
		int b = right.top().first;
		right.pop();
		area += (right.top().first - b) * right.top().second;
	}

	std::cout << area;
}

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<std::pair<int, int>> pole;
	for (auto i = 0; i < N; ++i) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		pole.push_back({ a,b });
	}

	make_roof(pole);
}
