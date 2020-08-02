#include <iostream>

int main()
{
	long long n = 0;
	std::cin >> n;

	long long an = 1;

	if (n == 1)
		std::cout << 1;
	else
	{
		for (int i = 1; i <= 20000000000; i++)
		{
			
			if (an < n && n <= an + 6 * i)
			{
				std::cout << i + 1;
				break;
			}
			an += 6 * i;
		}
	}
}
