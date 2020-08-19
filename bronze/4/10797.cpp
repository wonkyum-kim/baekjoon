#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> A;

	for (size_t i = 0; i < 5; ++i)
	{
		int a = 0;
		std::cin >> a;
		A.push_back(a);
	}

	int count = 0;

	for (auto x : A)
	{
		if (x == n)
			count++;
	}

	std::cout << count;
}
