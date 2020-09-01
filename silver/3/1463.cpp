#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

/*
점화식 f(N)
1. (N == 1)	0
2. (N%3==0) f(N/3)+1
3. (N%2==0) f(N/2)+1
4. (else) f(N-1) + 1
*/

void dp(const int n)
{
	std::vector<int> r(n + 1, std::numeric_limits<int>::max());
	r[1] = 0;	// base case
	for (auto i = 1; i < n; ++i) {
		r[i + 1] = std::min(r[i + 1], r[i] + 1);
		if (i * 2 <= n) {
			r[i * 2] = std::min(r[i * 2], r[i] + 1);
		}
		if (i * 3 <= n) {
			r[i * 3] = std::min(r[i * 3], r[i] + 1);
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
