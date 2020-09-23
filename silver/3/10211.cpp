#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

template<typename T>
int find_maximum_subarray_linear(const std::vector<T>& A)
{
	int max_sum = std::numeric_limits<int>::min();		// sentinel value
	int running_sum = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		if (running_sum <= 0)
			running_sum = A[i];
		else
			running_sum += A[i];

		if (running_sum > max_sum)
			max_sum = running_sum;
	}
	return max_sum;
}

int main()
{
	int test = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		std::vector<int> v;
		long long num;
		std::cin >> num;
		for (auto i = 0; i < num; i++)
		{
			int temp;
			std::cin >> temp;
			v.push_back(temp);
		}
		std::cout << find_maximum_subarray_linear(v) << '\n';
	}
}
