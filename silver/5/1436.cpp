#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::string> apocalypse;
	int possible = 666;

	while (apocalypse.size() < n) {
		std::string s = std::to_string(possible++);
		if (s.find("666") != std::string::npos) {
			apocalypse.push_back(s);
		}
	}
	std::cout << apocalypse.back();
}
