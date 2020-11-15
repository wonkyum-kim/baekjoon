#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>

void pinary(int n)
{
	if (n == 1) {
		std::cout << 1;
		return;
	}
	else {
		std::vector<long long> zero(n + 1);
		std::vector<long long> one(n + 1);
		// zero[1] = 0;
		one[1] = 1;
		for (auto i = 2; i <= n; ++i) {
			one[i] = zero[i - 1];
			zero[i] = one[i - 1] + zero[i - 1];
		}
		std::cout << one[n] + zero[n];
	}
}


int main()
{
	int n = 0;
	std::cin >> n;
	pinary(n);
}
