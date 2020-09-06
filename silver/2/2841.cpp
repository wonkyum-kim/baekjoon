#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

void count_fingering(const std::vector<std::pair<int, int>>& melody) {

	std::stack<int> line1;
	std::stack<int> line2;
	std::stack<int> line3;
	std::stack<int> line4;
	std::stack<int> line5;
	std::stack<int> line6;

	int count = 0;

	for (auto x : melody) {

		if (x.first == 1) {
			if (line1.empty()) {
				line1.push(x.second);
				count++;
			}
			else {
				while(line1.top() > x.second){
					line1.pop();
					count++;
					if (line1.empty())
						break;
				}
				if (!line1.empty()) {
					if (line1.top() < x.second) {
						line1.push(x.second);
						count++;
					}
				}
				else {
					line1.push(x.second);
					count++;
				}
			}
		}
		else if (x.first == 2) {
			if (line2.empty()) {
				line2.push(x.second);
				count++;
			}
			else {
				while (line2.top() > x.second) {
					line2.pop();
					count++;
					if (line2.empty())
						break;
				}
				if (!line2.empty()) {
					if (line2.top() < x.second) {
						line2.push(x.second);
						count++;
					}
				}
				else {
					line2.push(x.second);
					count++;
				}
			}
		}
		else if (x.first == 3) {
			if (line3.empty()) {
				line3.push(x.second);
				count++;
			}
			else {
				while (line3.top() > x.second) {
					line3.pop();
					count++;
					if (line3.empty())
						break;
				}
				if (!line3.empty()) {
					if (line3.top() < x.second) {
						line3.push(x.second);
						count++;
					}
				}
				else {
					line3.push(x.second);
					count++;
				}
			}
		}
		else if (x.first == 4) {
			if (line4.empty()) {
				line4.push(x.second);
				count++;
			}
			else {
				while (line4.top() > x.second) {
					line4.pop();
					count++;
					if (line4.empty())
						break;
				}
				if (!line4.empty()) {
					if (line4.top() < x.second) {
						line4.push(x.second);
						count++;
					}
				}
				else {
					line4.push(x.second);
					count++;
				}
			}
		}
		else if (x.first == 5) {
			if (line5.empty()) {
				line5.push(x.second);
				count++;
			}
			else {
				while (line5.top() > x.second) {
					line5.pop();
					count++;
					if (line5.empty())
						break;
				}
				if (!line5.empty()) {
					if (line5.top() < x.second) {
						line5.push(x.second);
						count++;
					}
				}
				else {
					line5.push(x.second);
					count++;
				}
			}
		}
		else if (x.first == 6) {
			if (line6.empty()) {
				line6.push(x.second);
				count++;
			}
			else {
				while (line6.top() > x.second) {
					line6.pop();
					count++;
					if (line6.empty())
						break;
				}
				if (!line6.empty()) {
					if (line6.top() < x.second) {
						line6.push(x.second);
						count++;
					}
				}
				else {
					line6.push(x.second);
					count++;
				}
			}
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
