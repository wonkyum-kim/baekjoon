#include <iostream>
#include <vector>
#include <algorithm>

long long find_max_crossing_subarray(std::vector<long long>& A, size_t low, size_t mid, size_t high)
{
	long long result = A[mid] * A[mid];		// sum * min_elem
	size_t i = mid;
	size_t j = mid;
	long long sum = A[mid];
	long long min_elem = A[mid];

	while (i > low || j < high) {
		if (j < high && (i == low || A[i - 1] < A[j + 1])) {
			sum += A[++j];
			min_elem = std::min(min_elem, A[j]);
		}
		else {
			sum += A[--i];
			min_elem = std::min(min_elem, A[i]);
		}
		result = std::max(result, sum * min_elem);
	}
	return result;
}

long long find_maximum_subarray(std::vector<long long>& A, size_t low, size_t high)
{
	if (low == high) {
		return A[low] * A[low];
	}
	size_t mid = (high + low) / 2;
	long long result = std::max(find_maximum_subarray(A, low, mid), find_maximum_subarray(A, mid + 1, high));
	return std::max(result, find_max_crossing_subarray(A, low, mid, high));
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<long long> A;
	for (auto i = 0; i < n; ++i) {
		long long a = 0;
		std::cin >> a;
		A.push_back(a);
	}
	std::cout << find_maximum_subarray(A, 0, n - 1);
}
