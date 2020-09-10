#include<list>
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

void make_list(std::list<char>& ls, const std::string& s)
{
	ls.push_back('*');
	for (auto i = 0; i < s.size(); ++i) {
		ls.push_back(s[i]);
		ls.push_back('*');
	}
}

void cursor_operation(std::list<char>& ls, const int m)
{
	// 처음 커서의 위치
	auto pos = std::prev(ls.end(), 1);

	for (auto i = 0; i < m; ++i) {
		char op = 0;
		std::cin >> op;
		char data = 0;
		// (* <-> data)를 커서 왼쪽에 삽입
		if (op == 'P') {
			std::cin >> data;
			ls.insert(pos, data);
			ls.insert(std::prev(pos, 1), '*');
		}
		else if (op == 'L') {
			// 커서가 첫번째 문자 앞을 벗어나지 않게 조절
			if (pos != ls.begin()) {
				pos = std::prev(pos, 2);
			}
		}
		else if (op == 'D') {
			// 커서가 마지막 문자 뒤를 벗어나지 않게 조절 
			if (pos != std::prev(ls.end(), 1)) {
				pos = std::next(pos, 2);
			}
		}
		else if (op == 'B') {
			// 첫 번째 문자 앞을 가리키는 커서가 아니라면 (* <-> data)를 삭제.
			if (pos != ls.begin()) {
				ls.erase(std::prev(pos, 2));
				ls.erase(std::prev(pos, 1));
			}
		}
	}
}

void print_list(std::list<char>& ls)
{
	while (true) {
		if (ls.front() != '*') {
			std::cout << ls.front();
		}
		ls.pop_front();
		if (ls.empty()) {
			break;
		}
	}
}

int main()
{
	// abcd
	std::string s;
	int m = 0;
	std::cin >> s >> m;

	// * means cursor
	// [ls.begin()] * <-> a <-> * <-> b <-> * <-> c <-> * <-> d <-> * <->ls.end()
	std::list<char> ls;
	make_list(ls, s);
	cursor_operation(ls, m);
	print_list(ls);
}
