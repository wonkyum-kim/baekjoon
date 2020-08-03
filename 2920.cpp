#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a{ 1,2,3,4,5,6,7,8 };
	std::vector<int> d{ 8,7,6,5,4,3,2,1 };
	std::vector<int> test;

	for (auto i = 0; i < 8; i++)
	{
		int k;
		std::cin >> k;
		test.push_back(k);
	}

	if (a == test)
		std::cout << "ascending";
	else if (d == test)
		std::cout << "descending";
	else
		std::cout << "mixed";
}
