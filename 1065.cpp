#include <iostream>

int main()
{
	auto i = 0;
	std::cin >> i;

	if (i <= 99)
		std::cout << i;
	else if (99 < i && i <= 999)
	{
		int count = 99;

		for (auto k = 100; k <= i; k++)
		{
			int k1 = k % 10;
			int k2 = ((k - k1) / 10) % 10;
			int k3 = k / 100;

			if (k2 - k1 == k3 - k2)
				count++;
		}
		std::cout << count;
	}
	else if (i == 1000)
		std::cout << 144;
}
