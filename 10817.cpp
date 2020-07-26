#include <iostream>
#include <array>
#include <algorithm>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	array<int, 3> s{ a, b, c };
	std::sort(s.begin(), s.end());
	std::cout << s[1];
	return 0;
}
