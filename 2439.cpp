#include <iostream>

int main()
{
	auto a = 0;
	std::cin >> a;

	for (int i = 1; i <= a; i++)
	{
		for (int k = a - i; k >= 1; k--)
		{
			std::cout << ' ';
		}

		for (int j = 1; j <= i; j++)
		{
			std::cout << '*';
		}

		std::cout << '\n';
	}
	return 0;
}
