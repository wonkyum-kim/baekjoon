#include <iostream>
#include <vector>

template<typename T>
int linearSearch(std::vector<T>& A, const T& target)
{
	for (int i = 0; i<A.size(); ++i)
	{
		if (A[i]==target)
			return i;
	}
	return -1;
}

int main()
{
	std::vector<int> A;
	int a = 0;

	for (int i = 0; i < 9; ++i)
	{
		std::cin >> a;
		A.push_back(a);
	}

	int max = A[0];

	for (int i = 0; i < 9; ++i)
	{
		if (max < A[i])
			max = A[i];
	}
	std::cout << max << '\n';
	std::cout << linearSearch(A, max)+1;
	return 0;
}
