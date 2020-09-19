#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long long N = 0;
	long long M = 0;
	std::cin >> N >> M;

	std::vector<long long> tree;
	for (auto i = 0; i < N; ++i) {
		long long temp = 0;
		std::cin >> temp;
		tree.push_back(temp);
	}

	long long low = 0;
	long long high = 1'000'000'000;
	long long result = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;

		for (auto i = 0; i < N; ++i) {
			if (tree[i] >= mid) {
				sum += (tree[i] - mid);
			}
		}

		if (sum >= M) {
			low = mid + 1;
			result = std::max(mid, result);
		}
		else if (sum < M) {
			high = mid - 1;
		}
	}

	std::cout << result;
}
