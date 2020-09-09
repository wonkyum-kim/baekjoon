#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

void input_numbers_to_deque(std::string& input ,std::deque<std::string>& arr)
{
	char x = 0;
	while (true) {
		std::cin >> x;
		if (x != '[' && x != ']' && x != ',') {
			input += x;
		}
		else if (x == ',') {
			arr.push_back(input);
			input.clear();
		}
		else if (x == ']') {
			if (!input.empty()) {
				arr.push_back(input);
				input.clear();
			}
			break;
		}
	}
}

void print_AC(bool& flag, std::deque<std::string>& arr)
{
	if (arr.empty()) {
		std::cout << "[]\n";
	}
	else if (arr.size() == 1) {
		std::cout << '[' << arr.front() << ']' << '\n';
	}
	else if (arr.size() > 1) {
		std::cout << '[';
		if (flag) {
			while (!arr.empty()) {
				std::cout << arr.front();
				arr.pop_front();
				if (arr.empty()) {
					break;
				}
				std::cout << ',';
			}
		}
		else {
			while (!arr.empty()) {
				std::cout << arr.back();
				arr.pop_back();
				if (arr.empty()) {
					break;
				}
				std::cout << ',';
			}
		}
		std::cout << ']' << '\n';
	}
}

void read_operations(const std::string& operations, std::deque<std::string>& arr)
{
	// true means forward direction, false means reverse direction.
	bool flag = true;
	for (auto j = 0; j < operations.length(); ++j) {
		if (operations[j] == 'R') {
			flag ? flag = false : flag = true;
		}
		else if (operations[j] == 'D') {
			if (arr.empty()) {
				std::cout << "error" << '\n';
				return;
			}
			else {
				// forward direction means delete a first element.
				// reverse direction means delete a last element.
				flag ? arr.pop_front() : arr.pop_back();
			}
		}
	}
	print_AC(flag, arr);
}


int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int test = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		std::string operations;
		std::cin >> operations;

		size_t n = 0;
		std::cin >> n;

		std::deque<std::string> arr;
		std::string input;

		input_numbers_to_deque(input, arr);
		read_operations(operations, arr);
	}
}
