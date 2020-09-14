#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long cross(std::vector<long long>& A, size_t low, size_t mid, size_t high)
{
	long long height = A[mid];
	long long width = 1;
	long long area = height * 1;
	size_t i = mid, j = mid;

	while (i > low || j < high) {
		if (j < high && (i == low || A[j + 1] > A[i - 1])) {
			height = std::min(height, A[++j]);
		}
		else {
			height = std::min(height, A[--i]);
		}
		width = j - i + 1;
		long long temp = width * height;
		area = std::max(area, temp);
	}
	return area;
}

long long histogram(std::vector<long long>& A, size_t low, size_t high) {
	if (high == low) {
		return A[high];
	}
	size_t mid = (high + low) / 2;

	long long result = std::max(histogram(A, low, mid), histogram(A, mid + 1, high));
	result = std::max(result, cross(A, low, mid, high));
	return result;
}

int main()
{
	while (true) {
		int test = 0;
		std::cin >> test;
		if (test == 0) {
			break;
		}
		std::vector<long long> A;
		for (auto i = 0; i < test; ++i) {
			long long temp = 0;
			std::cin >> temp;
			A.push_back(temp);
		}
		std::cout << histogram(A, 0, A.size() - 1) << '\n';
	}
}
