#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>


void dp(const int n)
{
	std::vector<int> r(n + 1, 0);
	r[1] = 0;	// base case
	for (auto i = 2; i <= n; ++i) {
		r[i] = r[i - 1] + 1;
		if (i % 2 == 0) {
			r[i] = std::min(r[i / 2] + 1, r[i]);
		}
		if (i % 3 == 0) {
			r[i] = std::min(r[i / 3] + 1, r[i]);
		}
	}
	std::cout << r[n];
}

int main()
{
	int n = 0;
	std::cin >> n;
	dp(n);
}
