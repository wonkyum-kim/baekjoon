#include <iostream>
#include <map>
#include <string>
#include <cctype>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	std::map<std::string, int> poke1;
	std::map<int, std::string> poke2;
	for (auto i = 1; i <= n; ++i) {
		std::string temp;
		std::cin >> temp;
		poke1.insert({ temp,i });
		poke2.insert({ i,temp });
	}
	
	for (auto i = 0; i < m; ++i) {
		std::string s;
		std::cin >> s;
		// 문자열인경우
		if (!isdigit(s[0])) {
			auto search = poke1.find(s);
			std::cout << search->second << '\n';
		}
		// 숫자인경우
		else {
			int idx = std::atoi(s.c_str());
			auto search = poke2.find(idx);
			std::cout << search->second << '\n';
		}
	}
}
