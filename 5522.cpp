#include <iostream>
#include <vector>
#include <string>

int main()
{
	auto sum = 0;
	std::vector<int> a;
	for (auto i = 0; i < 5; ++i)
	{
		int k;
		std::cin >> k;
		a.push_back(k);
		sum += a[i];
	}
	std::cout << sum;
}
