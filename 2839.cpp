#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int j;

	for (int i = 1000; i > -1; i--)
	{
		if (5 * i <= n)
		{
			j = 0;
			while(j<1668)
			{
				if ((5 * i + 3 * j) == n)
				{
					std::cout << i + j;
					break;
				}
				if (i == 0 && j == 1667)
					std::cout << -1;
				j++;
			}
			if ((5 * i + 3 * j) == n)
				break;
		}
		else
			continue;
	}
}
