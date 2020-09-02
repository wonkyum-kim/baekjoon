#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	int count = s.length();

	if (s.length() == 1) {
		std::cout << 1;
	}
	else {
		for (auto i = 0; i < s.length() - 1; ++i) {
			if (s.substr(i, 2) == "c=" || s.substr(i, 2) == "c-" || s.substr(i, 2) == "d-" || s.substr(i, 2) == "lj" || s.substr(i, 2) == "nj" || s.substr(i, 2) == "s=" || s.substr(i, 2) == "z=")
				count--;
		}
		for (auto i = 0; i < s.length() - 2; ++i) {
			if (s.substr(i, 3) == "dz=")
				count--;
		}
		std::cout << count;
	}
}
