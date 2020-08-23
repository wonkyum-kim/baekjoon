#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

int main()
{
	std::deque<int> d;

	int test = 0;
	std::cin >> test;

	for (int i = 0; i < test; ++i) {
		std::string s;
		std::cin >> s;

		if (s == "push_front") {
			int a = 0;
			std::cin >> a;
			d.push_front(a);
		}
		else if (s == "push_back") {
			int a = 0;
			std::cin >> a;
			d.push_back(a);
		}
		else if (s == "pop_front") {
			if (d.empty()) {
				std::cout << "-1\n";
			}
			else {
				std::cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty()) {
				std::cout << "-1\n";
			}
			else {
				std::cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size") {
			std::cout << d.size() << '\n';
		}
		else if (s == "empty") {
			if (d.empty()) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
		else if (s == "front") {
			if (d.empty()) {
				std::cout << "-1\n";
			}
			else {
				std::cout << d.front() << '\n';
			}
		}
		else if (s == "back") {
			if (d.empty()) {
				std::cout << "-1\n";
			}
			else {
				std::cout << d.back() << '\n';
			}
		}
	}
}
