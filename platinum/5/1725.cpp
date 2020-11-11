#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

long long histogram(const std::vector<long long>& A, const size_t low, const size_t high)
{
	// base case
	if (low == high) {
		return A[low];
	}

	// find a possible answer in the left subarray and the right subarray.
	size_t mid = (low + high) / 2;
	auto possible1 = std::max(find_maximum_subarray(A, low, mid), find_maximum_subarray(A, mid + 1, high));

	// find a possible answer in the crossing subarray.
	size_t i = mid;
	size_t j = mid;
	long long height = A[mid];
	long long width = 1;
	long long possible2 = A[mid] * 1;
	
	while (low < i || j < high) {
		if (j < high && (i == low || A[j + 1] > A[i - 1])) {
			height = std::min(height, A[++j]);
		}
		else {
			height = std::min(height, A[--i]);
		}
		width = j - i + 1;
		long long temp = height * width;
		possible2 = std::max(temp, possible2);
	}
	return std::max(possible1, possible2);
}

int main()
{
	long long n = 0;
	std::cin >> n;

	constexpr long long dummy = 0;
	std::vector<long long> A{ dummy };
	for (auto i = 0; i < n; ++i) {
		long long h = 0;
		std::cin >> h;
		A.push_back(h);
	}
	std::cout << histogram(A, 1, n);
}
