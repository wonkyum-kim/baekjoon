#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	// 위 삼각형(1~n)줄

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			std::cout << " ";
		}
		for (int k = 2 * i; k < 2 * n - 1; ++k)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}

	// 아래 삼각형 (n+1~2n-1)줄
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = n - i; j > 2; j--) 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * i + 3; ++k)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
	return 0;
}
