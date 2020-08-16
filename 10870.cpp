#include <iostream>
#include <limits>
#include <vector>

int fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	auto temp = fibo(n - 2) + fibo(n - 1);
	if (temp <= std::numeric_limits<int>::max())
		return temp;
	else
		return std::numeric_limits<int>::min();
}

int main()
{
	std::vector<int> v;
	for (int i = 0; i <= 20; ++i)
	{
		if (fibo(i) != std::numeric_limits<int>::min())
			v.push_back(fibo(i));
		else
			break;
	}

	int n;
	std::cin >> n;
	std::cout << v[n];
}
