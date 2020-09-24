#include <iostream>
#include <algorithm>
#include <vector>

void binary_search(int k, int n, std::vector<long long>& lans)
{
	long long low = 1;
	long long high = lans.back();
	long long mid = 0;
	long long result = 0;

	while (high - low >= 0)
	{
		long long count = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < k; ++i)
			count += lans[i] / mid;

		if (count >= n)
		{
			low = mid + 1;
			result = mid;
		}
		else {
			high = mid - 1;
		}
	}
	std::cout << result;
}

int main()
{
	int k = 0;
	int n = 0;
	std::cin >> k >> n;
	std::vector<long long> lans;

	for (int i = 0; i < k; i++) {
		long long temp = 0;
		std::cin >> temp;
		lans.push_back(temp);
	}
	std::sort(lans.begin(), lans.end());
	binary_search(k, n, lans);
}
