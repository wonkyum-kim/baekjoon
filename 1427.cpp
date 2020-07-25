#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	long long int num;
	std::cin >> num;

	std::vector<int> a;

	while (num>0)
	{
		int x = num % 10;
		a.push_back(x);
		num /= 10;
	}

	std::sort(a.begin(), a.end(), std::greater<int>());
	for (auto& x : a)
		std::cout << x;
}
