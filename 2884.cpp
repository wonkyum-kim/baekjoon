#include <iostream>

int main()
{
	auto h = 0;
	auto m = 0;
	std::cin >> h >> m;

	if (h>=0 && h<=23 && m >= 45 && m <= 59)
		std::cout << h << ' ' << m - 45;
	else if (h >= 0 && h <= 23 && 0 <= m && m < 45)
	{
		if (h >= 1)
			std::cout << h - 1 << ' ' << m - 45 + 60;
		else if (h == 0)
			std::cout << "23" << ' ' << m - 45 + 60;
	}
	return 0;
}
