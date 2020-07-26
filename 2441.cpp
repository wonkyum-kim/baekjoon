#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << ' ';
		for (int k = n; k > i; --k)
			std::cout << '*';
		std::cout << '\n';
	}
	return 0;
}
