#include <iostream>
#include <cmath>

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		int a = 0;
		std::cin >> a;
		sum += pow(a, 2);
	}
	std::cout << sum % 10;
}
