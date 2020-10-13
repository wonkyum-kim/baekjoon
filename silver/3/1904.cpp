#include <vector>
#include <iostream>
#include <algorithm>

void dp(int n)
{
	std::vector<int> tile(n + 1);
	/* 
	tile[1] = 1;	// 1
	tile[2] = 2;	// 00 11
	tile[3] = 3;	// 001 100 111
	tile[4] = 5;	// 0000 0011 1001 1100 1111
	tile[5] = 8;	// 00001 10000 00100 00111 10011 11001 11100 11111
	*/
	if (n == 1) {
		std::cout << 1;
	}
	else if (n == 2) {
		std::cout << 2;
	}
	else {
		tile[1] = 1;	
		tile[2] = 2;
		for (auto i = 3; i <= n; ++i) {
			tile[i] = (tile[i - 1] + tile[i - 2])% 15746;
		}
		std::cout << tile[n] % 15746;
	}
}

int main()
{
	int n = 0;
	std::cin >> n;
	dp(n);
}
