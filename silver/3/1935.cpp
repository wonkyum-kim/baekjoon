#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
#include <vector>


void insert_numbers(std::vector<int>& save_num, const int num)
{
	for (auto i = 0; i < num; ++i) {
		int temp = 0;
		std::cin >> temp;
		save_num.push_back(temp);
	}
}

void postfix_calculate(const std::vector<int>& save_num, const std::string& postfix) {

	std::stack<double> digit;

	for (auto i = 0; i < postfix.length(); ++i) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {

			double digit2 = digit.top();
			digit.pop();
			double digit1 = digit.top();
			digit.pop();

			if (postfix[i] == '+') {
				digit.push(digit1 + digit2);
			}
			else if (postfix[i] == '-') {
				digit.push(digit1 - digit2);
			}
			else if (postfix[i] == '*') {
				digit.push(digit1 * digit2);
			}
			else if (postfix[i] == '/') {
				digit.push(digit1 / digit2);
			}
		}
		else {
			digit.push(save_num[postfix[i] - 65]);
		}
	}

	std::cout << std::fixed << std::setprecision(2) << digit.top();
}

int main()
{
	int num = 0;
	std::cin >> num;
	std::string postfix_template;
	std::cin >> postfix_template;
	std::vector<int> save_num;
	insert_numbers(save_num, num);
	postfix_calculate(save_num, postfix_template);
}
