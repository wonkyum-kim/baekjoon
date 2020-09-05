#include <iostream>
#include <stack>
#include <string>

void infix_to_postfix(const std::string& infix) {

	std::stack<char> operation;
	for (auto i = 0; i < infix.length(); ++i) {
		if (infix[i] == '(') {
			operation.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (true) {
				if (operation.top() == '(') {
					operation.pop();
					break;
				}
				else {
					std::cout << operation.top();
					operation.pop();
				}
			}
		}
		else if (infix[i] == '+' || infix[i] == '-') {
			// 우선 순위가 높은 것 : + - * /
			// 우선 순위가 낮은 것 : ( empty
			while (true) {
				if (operation.empty() || operation.top() == '(') {
					operation.push(infix[i]);
					break;
				}
				else {
					std::cout << operation.top();
					operation.pop();
				}
			}
		}
		else if (infix[i] == '*' || infix[i] == '/') {
			// 우선 순위가 높은 것 : * /
			// 우선 순위가 낮은 것 : ( empty + -
			while (true) {
				if (!operation.empty()) {
					if (operation.top() == '*' || operation.top() == '/') {
						std::cout << operation.top();
						operation.pop();
					}
					else if (operation.top() == '(' || operation.top() == '+' || operation.top() == '-') {
						operation.push(infix[i]);
						break;
					}
				}
				else {
					operation.push(infix[i]);
					break;
				}
			}
		}
		else {
			std::cout << infix[i];
		}
	}

	if (!operation.empty()) {
		while (true) {
			if (operation.empty()) {
				break;
			}
			else {
				std::cout << operation.top();
				operation.pop();
			}
		}
	}
}


int main()
{
	std::string infix;
	std::cin >> infix;
	infix_to_postfix(infix);
}
