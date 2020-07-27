#include <iostream>
#include <vector>

int main()
{
	std::vector<int> A;
	for (auto i = 0; i < 6; ++i)
	{
		int a;
		std::cin >> a;
		A.push_back(a);
	}

	std::vector<int> B{ 1,1,2,2,2,8 };

	for (auto j = 0; j < 6; ++j)
		std::cout << B[j] - A[j] << ' ';
}
