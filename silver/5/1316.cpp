#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int num = 0;
	std::cin >> num;

	std::string s;
	std::vector<std::string> v;
	std::vector<int> count(num);

	int sak = num;

	for (auto i = 0; i < num; ++i) {
		std::cin >> s;
		auto last = std::unique(s.begin(), s.end());
		s.erase(last, s.end());
		v.push_back(s);

		if (s.length() > 1) {
			for (auto j = 0; j < s.length() - 1; ++j) {
				for (auto k = j + 1; k < s.length(); ++k) {
					if (s[j] == s[k]) {
						count[i]++;
					}
				}
			}
		}
	}

	for (auto i = 0; i < num; i++) {
		if (count[i] != 0)
			sak--;
	}
	std::cout << sak;
}
