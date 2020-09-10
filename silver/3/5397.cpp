#include<list>
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

// * means cursor
// [ls.begin()] * <-> a <-> * <-> b <-> * <-> c <-> * <-> d <-> * <->ls.end()

void make_list(std::list<char>& ls, const std::string& s)
{
	ls.push_back('*');
	auto pos = ls.begin();
	for (auto i = 0; i < s.size(); ++i) {
		// 이전 커서를 가리킴.
		if (s[i] == '<' && pos != ls.begin()) {
			pos = std::prev(pos, 2);
		}
		// 다음 커서를 가리킴
		else if (s[i] == '>' && pos != std::prev(ls.end(), 1)) {
			pos = std::next(pos, 2);
		}
		// 이전 커서와 원소를 삭제.
		else if (s[i] == '-' && pos != ls.begin()) {
			ls.erase(std::prev(pos, 2));
			ls.erase(std::prev(pos, 1));
		}
		else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			ls.insert(pos, '*');
			ls.insert(pos, s[i]);
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
	std::cout << '\n';
}

int main()
{
	// abcd
	std::string s;
	int m = 0;
	std::cin >> m;

	for (auto i = 0; i < m; ++i) {
		std::cin >> s;
		std::list<char> ls;
		make_list(ls, s);
		print_list(ls);
	}
}
