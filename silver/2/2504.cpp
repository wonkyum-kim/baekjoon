#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	std::stack<char> stack;
	int ans = 0;
	int temp = 1;
	for (auto i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			stack.push(s[i]);
			temp *= 2;
		}
		else if (s[i] == '[') {
			stack.push(s[i]);
			temp *= 3;
		}
		else if (s[i] == ')') {
			if (stack.empty() || stack.top() != '(') {
				goto impossible;
			}
			else if (s[i-1] == '(') {
				ans += temp;
			}
			stack.pop();
			temp /= 2;
		}
		else {
			if (stack.empty() || stack.top() != '[') {
				goto impossible;
			}
			else if (s[i - 1] == '[') {
				ans += temp;
			}
			stack.pop();
			temp /= 3;
		}
	}

	if (!stack.empty()) {
		goto impossible;
	}
	std::cout << ans;
	return 0;

impossible:
	std::cout << 0;
}
