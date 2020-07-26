#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> A;

	for (int i = 0; i < 10; i++)
	{
		int x = 0;
		std::cin >> x;
		int y = x % 42;
		A.push_back(y);
	}
	
	std::sort(A.begin(), A.end());
	auto last = std::unique(A.begin(), A.end());
	A.erase(last, A.end());

	std::cout<< A.size();
}
