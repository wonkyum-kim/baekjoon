#include <iostream>

int main()
{
	auto d = 0;
	std::cin >> d;
	if (d >= 1 && d <= 9)
		for (int i = 1; i < 10; ++i)
			std::cout << d <<' '<< '*' <<' '<< i <<' '<< '=' << ' '<<d * i << '\n';
	return 0;
}
