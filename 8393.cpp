#include <iostream>
#include <vector>

int main()
{
	auto T = 0;
	std::cin >> T;

	if (T >= 1 && 1 <= 10000)
		std::cout << T * (T + 1) / 2;
	return 0;
}
