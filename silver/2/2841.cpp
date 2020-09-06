#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

void count_fingering(const std::vector<std::pair<int, int>>& melody) {

	std::vector<std::stack<int>> line;
	std::stack<int> dummy;
	std::stack<int> line1;
	std::stack<int> line2;
	std::stack<int> line3;
	std::stack<int> line4;
	std::stack<int> line5;
	std::stack<int> line6;
	line.push_back(dummy);
	line.push_back(line1);
	line.push_back(line2);
	line.push_back(line3);
	line.push_back(line4);
	line.push_back(line5);
	line.push_back(line6);
	int count = 0;

	for (auto x : melody) {
		// 비어있다면
		if (line[x.first].empty()) {
			// 새로 누른다.
			line[x.first].push(x.second);
			count++;
		}
		// 비어있지 않다면
		else {
			// 더 작은 프렛을 눌러야 한다면
			if (line[x.first].top() > x.second) {
				while (true) {
					line[x.first].pop();
					count++;
					// 스택이 비거나 같거나 더 커질 때까지 pop
					if (line[x.first].empty() || line[x.first].top() <= x.second) {
						break;
					}
				}
				// 스택이 비었거나 이미 누른 상태가 아니라면
				if (line[x.first].empty() || line[x.first].top() != x.second) {
					line[x.first].push(x.second);
					count++;
				}
			}
			// 더 큰 프렛을 눌러야 한다면
			else if (line[x.first].top() < x.second) {
				// 새로 누른다.
				line[x.first].push(x.second);
				count++;
			}
			// 이미 누른 프렛이라면 아무것도 하지 않는다.
		}
	}
	std::cout << count;
}


int main()
{
	int N = 0;
	int P = 0;
	std::cin >> N >> P;
	std::vector<std::pair<int, int>> melody;

	for (auto i = 0; i < N; ++i) {
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		melody.push_back({ a,b });
	}
	count_fingering(melody);
}
