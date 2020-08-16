#include <iostream>
#include <vector>

int main()
{
	long long L, P;
	std::cin >> L >> P;
	auto total = L * P;

	std::vector<long long> A;
	for (auto i = 0; i < 5; ++i)
	{
		long long a;
		std::cin >> a;
		A.push_back(a);
	}

	for (auto i = 0; i < 5; ++i)
	{
		std::cout << A[i] - total << ' ';
	}
}
