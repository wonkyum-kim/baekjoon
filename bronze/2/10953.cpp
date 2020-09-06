#include <iostream>
#include <string>

int main()
{
	int test = 0;
	std::cin >> test;
	for (auto i = 0; i < test; ++i) {
		std::string s;
		std::cin >> s;
		int a = s[0] - 48;
		int b = s[2] - 48;
		std::cout << a + b << '\n';
	}
}
