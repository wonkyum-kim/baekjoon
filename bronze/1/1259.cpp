#include <iostream>
#include <algorithm>
#include <string>

std::string mirror_ends(const std::string& in)
{
	return std::string(in.begin(),
		std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}


int main()
{
	while (true) {
		std::string s;
		std::cin >> s;
		if (s == "0")
			break;
		else {
			if (s == mirror_ends(s)) {
				std::cout << "yes\n";
			}
			else {
				std::cout << "no\n";
			}
		}
	}
}
