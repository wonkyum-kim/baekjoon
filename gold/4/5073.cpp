#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

bool is_nested(const std::string& s)
{
	std::stack<std::string> tag;
	if (s.length() <= 1) {
		return true;
	}
	else {
		for (auto i = 0; i < s.length() - 1; ++i) {
			// find opening tags.
			if (s[i] == '<' && s[i + 1] != '/') {
				auto it = std::find(s.begin() + i, s.end(), '>');
				auto temp = std::distance(s.begin() + i, it);
				std::string cand = s.substr(i + 1, temp - 1);
				// don't use <br />.
				if (cand != "br /") {
					// find attributes.
					auto n = cand.find("href");
					if (n == std::string::npos) {
						tag.push(cand);
					}
					else {
						std::string cand2 = cand.substr(0, n - 1);
						tag.push(cand2);
					}
				}
			}
			else if (s[i] == '<' && s[i + 1] == '/') {
				if (tag.empty()) {
					return false;
				}
				// find closing tags.
				auto it = std::find(s.begin() + i, s.end(), '>');
				size_t temp = std::distance(s.begin() + i, it);
				// compare tags.
				if (tag.top() == s.substr(i + 2, temp - 2)) {
					tag.pop();
				}
			}
		}
		if (tag.empty()) {
			return true;
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (true) {
		std::string s;
		std::getline(std::cin, s);
		if (s == "#") {
			break;
		}
		if (is_nested(s)) {
			std::cout << "legal" << '\n';
		}
		else {
			std::cout << "illegal" << '\n';
		}
	}
}
