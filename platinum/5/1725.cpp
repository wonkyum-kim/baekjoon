#include <vector>
#include <iostream>
#include <algorithm>

long long find_max_crossing_subarray(const std::vector<long long>& A, const size_t low, const size_t mid, const size_t high)
{
	long long height = A[mid];
	long long width = 1;
	long long result = A[mid];
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
		result = std::max(result, temp);
	}
	return result;
}

long long find_maximum_subarray(const std::vector<long long>& A, const size_t low, const size_t high)
{	
	// 1칸의 사각형의 넓이=높이
	if (low == high) {
		return A[low];
	}
	size_t mid = (low + high) / 2;
	long long result = std::max(find_maximum_subarray(A,low,mid),find_maximum_subarray(A,mid+1,high));
	result = std::max(result, find_max_crossing_subarray(A, low, mid, high));

	return result;
}

int main()
{
	long long N = 0;
	std::cin >> N;
	std::vector<long long> height;

	constexpr long long dummy = 0;
	height.push_back(dummy);
	// N번째 사각형의 높이는 height[N]이다.
	for (auto i = 1; i <= N; ++i) {
		long long temp = 0;
		std::cin >> temp;
		height.push_back(temp);
	}
	std::cout << find_max_crossing_subarray(height, 1, (1 + N) / 2, N);
}

// 두 함수가 같이 시너지를 내야 정답이 나오는구나...
