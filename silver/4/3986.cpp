#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

// 3986

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::string> s;

	for (auto i = 0; i < n; ++i) {
		std::string temp;
		std::cin >> temp;
		s.push_back(temp);
	}

	std::stack<char> alpha;
	int count = 0;

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < s[i].size(); ++j) {
			// stack is empty.
			if (alpha.empty()) {
				alpha.push(s[i][j]);
			}
			// stack is not empty.
			else {
				// the top element in the stack is not the character to input
				if (alpha.top() != s[i][j]) {
					alpha.push(s[i][j]);
				}
				// the top element in the stack is the character to input
				else {
					alpha.pop();
				}
			}
		}
		// empty stack means a good word.
		if (alpha.empty()) {
			count++;
		}
		// clear the stack.
		else {
			while (true) {
				alpha.pop();
				if (alpha.empty()) {
					break;
				}
			}
		}
	}

	std::cout << count;

}
